#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n,m;
pair<int,int> t1,t2;
map<pair<int,int>,bool> vis;

int D(pair<int,int> p1,pair<int,int> p2){
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}


int Scan(int x,int y){
	// return D({x,y},t1) + D({x,y},t2);
	cout << "SCAN " << x << ' ' << y << endl;
	fflush(stdout);
	int res;
	cin>>res;

	return res;
}

int Dig(int x,int y){
	// return (D({x,y},t1) == 0 || D({x,y},t2) == 0);
	cout << "DIG " << x << ' ' << y << endl;
	fflush(stdout);
	int res;
	cin>>res;
	return res;
}

vector<pair<pair<int,int>,pair<int,int>>> prs;

pair<int,int> best(){

	pair<int,int> res = {1,1};
	int mn = 100000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[{i,j}])continue;
			vector<int> f(100,0);
			for(int k=0;k<prs.size();k++){
				int dist = D({i,j} , prs[k].first) + D({i,j} , prs[k].second);
				f[dist]++;
			}
			int mx = 0;
			for(int k=0;k<100;k++)mx = max(mx , f[k]);
			if(mx == 0)continue;
			if(mx < mn){
				mn = mx;
				res = {i,j};
			}
		}
	}
	vis[res] = 1;
	// cerr << "! " << mn << ' ' << res.first << ' ' << res.second << '\n';
	return res;

}

void ask(pair<int,int> poin){
	int r = poin.first;
	int c = poin.second;
	int dist = Scan(r,c);

	vector<pair<pair<int,int>,pair<int,int>>> nxt;

	for(int i=0;i<prs.size();i++){
		int cur = D({r,c} , prs[i].first) + D({r,c} , prs[i].second);
		if(cur == dist){
			nxt.push_back(prs[i]);
		}
	}
	// cerr << prs.size() << '\n';
	prs = nxt;
	// cerr << prs.size() << '\n';

}


void gen(){
	// n = m = 16	;
	n = 6;
	m = 10;
	// n = uniform_int_distribution<int>(1, 16)(rng);
	// m = uniform_int_distribution<int>(1, 16)(rng);

	t1 = {4,8};
	t2 = {5,2};
	// do{
	// 	t1 = {uniform_int_distribution<int>(1, n)(rng),uniform_int_distribution<int>(1, m)(rng)};
	// 	t2 = {uniform_int_distribution<int>(1, n)(rng),uniform_int_distribution<int>(1, m)(rng)};
	// }while(t1 == t2);
}

void solve(){
	cin>>n>>m;
	// gen();
	vis.clear();
	prs.clear();

	{
		vector<pair<int,int>> tmp;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				tmp.push_back({i,j});
			}
		}

		for(int i=0;i<tmp.size();i++){
			for(int j=i+1;j<tmp.size();j++)
				prs.push_back({tmp[i] , tmp[j]});
		}

	}

	for(int i=1;i<=4;i++){
		// cerr << prs.size() << '\n';
		ask(best());
	}
	assert(prs.size() <= 3);
	// cerr << prs.size() << '\n';
	// if(prs.size() > 2){
	// 	cerr << n << ' ' << m << '\n';
	// 	cerr << t1.first << ' ' << t1.second << '\n';
	// 	cerr << t2.first << ' ' << t2.second << '\n';
	// 	exit(0);
	// }

	if(prs.size() == 3){

		for(int i=0;i<prs.size();i++){
			for(int j=0;j<prs.size();j++){
				if(i == j)continue;
				if(prs[i].first == prs[j].first || prs[i].first == prs[j].second){
					if(Dig(prs[i].first.first,prs[i].first.second)){
						if(Dig(prs[i].second.first,prs[i].second.second)){
							return;
						}else{
							Dig(prs[j].second.first,prs[j].second.second);
							return;
						}
					}
					for(int x=0;x<prs.size();x++){
						if(x == i || x == j)continue;
						Dig(prs[x].first.first,prs[x].first.second);
						Dig(prs[x].second.first,prs[x].second.second);
						return;
					}
					assert(0);
				}
			}
		}
		assert(0);
	}else{
		if(Dig(prs[0].first.first,prs[0].first.second)){
			Dig(prs[0].second.first,prs[0].second.second);
		}else{
			assert(prs.size() == 2);
			Dig(prs[1].first.first,prs[1].first.second);
			Dig(prs[1].second.first,prs[1].second.second);
		}
	}


}

int main(){
	fast

	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/