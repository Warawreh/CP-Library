#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> dp,par;
vector<vector<int>> g,depth;
int n,m;
int mx;

void dfs(int u,int p = 0){
	dp[u] = dp[p] + 1;
	depth[dp[u]].push_back(u);
	mx = max(mx , dp[u]);
	par[u] = p;
	for(int v : g[u]){
		if(v == p || dp[v])continue;
		dfs(v,u);
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;

		g.clear();par.clear();
		depth.clear();
		dp.clear();
		mx = 0;
		par.resize(n+1);
		dp.resize(n+1);
		depth.resize(n + 1);
		g.resize(n+1);
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		if(mx * 2 >= n){
			cout << "PATH\n";
			int u = depth[mx].back();
			vector<int> ans;
			while(u){
				ans.push_back(u);
				u = par[u];
			}
			cout << ans.size() << '\n';
			for(int i : ans)cout << i << ' ';
			cout << '\n';
			continue;
		}
		vector<pair<int,int>> ans;
		for(int i=mx;i>0;i--){
			while(depth[i].size() > 1){
				int u = depth[i].back();
				depth[i].pop_back();
				int v = depth[i].back();
				depth[i].pop_back();
				ans.push_back({u,v});
			}
		}
		cout << "PAIRING\n";
		cout << ans.size() << '\n';
		for(auto a : ans)cout << a.first << ' ' << a.second << '\n';
	}
}