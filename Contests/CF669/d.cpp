#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<pair<int,int>,int> w;
vector<vector<int>> g;
vector<int> dp;
string ans;
int n,m;

int dfs(int u,int p = 0){
	if(dp[u] != -1)return dp[u];
	dp[u] = 1e9;
	vector<int> t(3,1e9);
	for(int v : g[u]){
		// if(lvl[v] < lvl[u])continue;
		// cerr << u << ' ' << v << ' ' << w[{u,v}] << '\n';
		int res = dfs(v,u);
		t[w[{u,v}] - 1] = min(t[w[{u,v}] - 1],res + 1);
	}
	if(t[1] > t[0])ans[u-1] = '1';
	int x = max(t[0] , t[1]);
	// cerr << u << ' ' << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
	return dp[u] = min(x , t[2]);
}

int main(){
	fast
	cin>>n>>m;
	ans = string(n,'0');
	g.resize(n+1);
	dp.resize(n+1,-1);
	for(int i=0;i<m;i++){
		int u,v,t;
		cin>>u>>v>>t;
		g[u].push_back(v);
		w[{u,v}] |= (1<<t);
	}
	dp[n] = 0;
	int res = dfs(1);
	if(res == 1e9)res = -1;
	cout << res << '\n';
	cout << ans << '\n';
}