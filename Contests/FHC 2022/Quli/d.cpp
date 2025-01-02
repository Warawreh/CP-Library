#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int Z = 600;

void solve(){
	int n,m,q;
	cin>>n>>m>>q;

	vector<vector<pair<int,int>>> g(n);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	map<pair<int,int> , ll> ans;

	for(int u=0;u<n;u++){
		if(g[u].size() > Z){

			for(auto &[v,w] : g[u]){

				for(auto &[v2,w2] : g[v]){
					if(v2 == u)continue;
					ans[{u , v2}] += min(w , w2);
				}
			}

		}
	}

	while(q--){
		int u,v;
		cin>>u>>v;
		u--;v--;

		if(g[u].size() > g[v].size())swap(u,v);

		if(g[u].size() > Z)cout << ans[{u,v}] << ' ';
		else{

			unordered_map<int , int> hv;
			ll ans = 0 ;
			for(auto &[x,w] : g[u]){
				hv[x] = w;
			}

			for(auto &[x,w] : g[v]){
				if(x == u){
					ans += w + w;
					continue;
				}
				if(hv[x] != 0)ans += min(hv[x] , w);
			}
			hv.clear();
			cout << ans << ' ';

		}
	}
	ans.clear();
	g.clear();
	cout << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}