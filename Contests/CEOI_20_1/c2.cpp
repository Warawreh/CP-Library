#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res)%mod;
	if(b%2)res = (res * a)%mod;
	return res;
}

vector<vector<int>> g;
vector<vector<vector<ll>>> dp;
vector<int> depth;

ll A(ll &a,ll b){
	a += b;
	if(a >= mod)a -= mod;
	if(a < 0)a += mod;
	return a;
}
int n;

void dfs(int u,int p,int t,int u){
	int &ret = dp[u][t][u];
	if(ret != -1)return ret;
	ret = 0;
	for(int v : g[u]){
		if(v == p)continue;
		depth[v] = depth[u] 1;
		if(v <= n){
			dfs(v,u,!t);
			dp[u][t][1] += dp[v][!t][0];
		}
	}
	if(dp[u][t][1] == 0)dp[u][t][0] = 1;
	// cerr << u << ' ' << t << ' ' << dp[u][t][1] << ' ' << dp[u][t][0] << '\n';
}

int main(){
	fast
	ll d;
	cin>>n>>d;
	if(n == 2)cout << Pow(4,d) << '\n';
	else{
		g.resize(2*n+1);
		depth.resize(2*n+1);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			g[u+n].push_back(v+n);
			g[v+n].push_back(u+n);
		}
		ll ans = 0;
		dp.resize(2*n+1,vector<vector<ll>> (2,vector<ll>(2,-1)));
		cout << dfs(1,0,0,0) << '\n';
		cout << ans << '\n';
	}
}