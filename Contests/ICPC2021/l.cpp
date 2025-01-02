#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Trie{
	vector<vector<pair<int,int>>> g;
	vector<int> hv,sz;
	vector<pair<int,int>> mx;
	int max_edge;

	void init(){
		max_edge = 0;
		g.push_back(vector<pair<int,int>>(0));
		hv.push_back(0);
		mx.push_back({0,0});
	}

	void add(vector<int> val){
		int cur = 0;
		for(int k=0;k<val.size();k++){
			int b = val[k];

			bool fnd = false;
			// cerr << cur << ' ' << g.size() << '\n';
			for(auto &[v,u] : g[cur]){
				if(v == b){
					b = u;
					fnd = 1;
					break;
				}
			}

			if(!fnd){
				if(b > mx[cur].first){
					mx[cur].second = mx[cur].first;
					mx[cur].first = b;
				}else if(b > mx[cur].second)mx[cur].second = b;

				// assert(b == val[k]);
				g[cur].push_back({b,g.size()});
				hv.push_back(0);
				cur = g.size();
				g.push_back(vector<pair<int,int>>(0));
				mx.push_back({0,0});


			}else{
				cur = b;
			}
			hv[cur]++;
		}
		
	}

	void sortEm(){
		for(int i=0;i<g.size();i++)
			sort(all(g[i]));
	}

	int get(vector<int> val){

		// cerr << "\nW ";	
		// for(int w : val)
		// 	cerr << w << ' ';
		// cerr << '\n';

		int cur = 0;
		if(hv[cur] == 1)return 0;

		for(int k=0;k<val.size();k++){
			int b = val[k];
			bool fnd = false;
			for(auto &[v,u] : g[cur]){
				if(v == b){
					b = u;
					fnd = 1;
					break;
				}
			}
			assert(fnd);

			if(hv[b] == 1){
				int at = lower_bound(all(g[cur]) , make_pair(val[k] , 0)) - g[cur].begin();
				// cerr << val[k] << ' ' << g[cur][at].first << '\n';

				if(at == g[cur].size() - 1)return g[cur][max(0,at-1)].first;
				else return g[cur][at].first;
				// if(mx[cur].first == val[k])
				// else return mx[cur].first;
			}
			
			cur = b;
		}
		assert(0);
		return 0;
	}
};

const int nax = 101;
vector<int> dst[nax][nax];
int main(){
    fast
    int n,m;
    cin>>n>>m;
    swap(n,m);
    vector<string> g(n);
    vector<pair<int,int>> marks;
    for(int i=0;i<n;i++){
    	cin>>g[i];
    	for(int j=0;j<m;j++)
    		if(g[i][j] == 'X')
    			marks.push_back({i,j});
    }

    vector<int> comp;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		// if(i != 0 || j != 4)continue;
    		vector<int> d;

    		for(auto &[r,c] : marks){
    			int mx = max(abs(i - r) , abs(j - c));
    			int cr = i - (mx - 1);
    			int cc = j - (mx - 1);
    			cr--;
    			mx = (mx - 1) + (mx);
    			int cur = mx * mx;	
    			// cerr << r << ' ' << c << ' ' << cr << ' ' << cc << ' ' << mx << ' ' << cur << '\n';


    			//Go right
    			if(cr == r && c >= cc){
    				d.push_back(cur + abs(c - cc));
    				continue;
    			}else{
    				cc += mx;
    				cur += mx;
    			}
    			mx++;

    			//Go down
    			if(cc == c && r >= cr){
    				d.push_back(cur + abs(r - cr));
    				continue;
    			}else{
    				cr += mx;
    				cur += mx;
    			}

    			//Go left;
    			if(cr == r && c <= cc){
    				d.push_back(cur + abs(c - cc));
    				continue;
    			}else{
    				cc -= mx;
    				cur += mx;
    			}
    			//Go Up
    			if(cc == c && r <= cr){
    				d.push_back(cur + abs(r - cr));
    				continue;
    			}
    			assert(0);
    		}
    		sort(all(d));

    		// cout << i << " , " << j << '\n';
    		for(int a : d){
    			comp.push_back(a);
    			// cout << a << ' ';
    		}
    		dst[i][j] = d;
    		// cout << '\n' << '\n';
    	}
    }
    sort(all(comp));
	comp.resize(unique(all(comp)) - comp.begin());

	Trie t;
	t.init();

	// for(int w : comp)
	// 	cerr << w << ' ';
	// cerr << '\n';

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			vector<int> nd = dst[i][j];
			for(int &x : nd)x = lower_bound(all(comp) , x) - comp.begin();
			t.add(nd);

		}
	}

	t.sortEm();
	ll sum = 0;
	ll mx = 0;
	vector<pair<int,int>> res;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){

			vector<int> nd = dst[i][j];
			for(int &x : nd)x = lower_bound(all(comp) , x) - comp.begin();
			
			ll cur = comp[t.get(nd)];

			if(dst[i][j][0] == 3){

				// cout << i << ' ' << j << '\n';
				// cout << cur << '\n';
				// for(int x : dst[i][j])
				// 	cout << x << ' ';
				// cout << '\n' << '\n';
			}
			if(cur == 18){
				cerr << i << ' ' << j << ' ' << cur << '\n';
			}
			sum += cur;
			if(cur > mx){
				mx = cur;
				res.clear();
			}
			if(cur == mx)res.push_back({n-i,j+1});

		}
	}

	sort(all(res));

	// sort(all(res) , [](pair<int,int> a,pair<int,int> b){
	// 	if(a.second == b.second)return a.first < b.first;
	// 	return a.second < b.second;
	// });
	cout << setprecision(3) << fixed << sum/ld(n*m) << '\n';
	cout << mx << '\n';
	for(auto &[i,j] : res)
		cout << '(' << j << ',' << i << ')' << ' ';
	cout << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/
