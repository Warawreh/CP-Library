#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<pair<int,int> , vector<int>> edge;

int main(){
    fast
    int n,c;
    cin>>n>>c;
    vector<int> ans,rem,t2;
    vector<vector<int>> op(n);
    vector<int> vv = {c};
    for(int i=0;i<n;i++){
    	op[i].resize(3);
    	for(int j=0;j<3;j++){
    		cin>>op[i][j];
    		if(j < 2)vv.push_back(op[i][j]);
    	}
    }
    sort(all(vv));
	vv.resize(unique(all(vv)) - vv.begin());

	int sz = vv.size();
	c = lower_bound(all(vv) , c) - vv.begin();

	vector<vector<pair<int,int>>> g(sz);
	vector<int> in(sz),out(sz);

	for(int i=0;i<n;i++){
		int u = (op[i][0] = lower_bound(all(vv) , op[i][0]) - vv.begin());
		int v = (op[i][1] = lower_bound(all(vv) , op[i][1]) - vv.begin());

		if(op[i][2] == 0 && u != c){
			t2.push_back(i);
			continue;
		}else if(op[i][2] == 0){
			rem.push_back(i);
			continue;
		}

		in[v]++;
		out[u]++;

		g[u].push_back({v , i});
		edge[{v,u}].push_back(i);
	}

	// if(t2.size() == n){
	// 	cout << "Yes\n";
	// 	for(int i=0;i<n;i++)cout << i + 1 << ' ';
	// 	cout << '\n';
	// 	return 0;
	// }
	int bf = (out[c] == in[c] + 1);
	int bn = -1;
	int bd = 0;
	for(int i=0;i<sz;i++){
		if(i == c)continue;
		if(out[i] > in[i]){
			cout << "No\n";
			return 0;
		}	

		if(in[i] == out[i] + 1){
			if(bd){
				cout << "No\n";
				return 0;
			}
			
			g[i].push_back({c , -1});
			in[c]++;
			out[i]++;
			bn = i;

			bd = 1;
		}else if(in[i] > out[i]){	
			cout << "No\n";
			return 0;
		}

	}

	// cerr << c << '\n';
	// cerr << out[c] << ' ' << in[c] << '\n';
	// cerr << bf << ' ' << bd << '\n';
	if(bf ^ bd){
		cout << "No\n";
		return 0;
	}

	vector<int> st;
	st.push_back(c);

	for(int i=0;i<sz;i++)reverse(all(g[i]));

	vector<int> path;
    vector<int> circuit; 
    path.push_back(0);
    int u = c;
 
    while (path.size()){
        if(g[u].size()){
            path.push_back(u);
            int v = g[u].back().first;
            g[u].pop_back();
            u = v;
        }else{
            circuit.push_back(u);
            // cerr << circuit.back() << '\n';
            u = path.back();
            path.pop_back();
        }
    }
    ans = t2;
 		
 	reverse(all(circuit));
    for (int i=0; i<circuit.size(); i++){
    	if((circuit[i] == c && circuit[(i - 1 + circuit.size())%circuit.size()] == bn) || bn == -1){
    		// cerr << circuit[i] << ' ' << circuit[(i - 1 + circuit.size())%circuit.size()] << ' ' << i << '\n';
    		int u = circuit[i];
    		for(int j=i+1;j<circuit.size();j++){
    			int v = circuit[j];
    			// cerr << u << ' ' << v << ' ' << edge[{v , u}].size() << '\n';
    			if(!edge[{v , u}].size()){
    				break;
    			}
    			ans.push_back(edge[{v , u}].back());
    			if(rem.size() && v != op[rem.back()][0]){
					ans.push_back(rem.back());
					rem.pop_back();
    			}
    			edge[{v , u}].pop_back();
    			u = v;
    		}
    		// cerr << u << ' ' << circuit[1] << '\n';
    		for(int j=1;j<i;j++){
    			int v = circuit[j];
    			// cerr << u << ' ' << v << ' ' << edge[{v , u}].size() << '\n';
    			if(!edge[{v , u}].size())break;
    			ans.push_back(edge[{v , u}].back());
    			if(rem.size() && v != op[rem.back()][0]){
					ans.push_back(rem.back());
					rem.pop_back();
    			}
    			edge[{v , u}].pop_back();
    			u = v;
    		}
    		break;
    	}
    }
    cerr << ans.size() << '\n';

	if(rem.size()){
		cout << "No\n";
		return 0;
	}

	if(ans.size() != n){
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";
	for(int i=0;i<ans.size();i++){
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
}
