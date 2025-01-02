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

const int nax = 1010;
int dp[nax][nax][2][2];
vector<int> depth,par;

void go(int u,int p){
	par[u] = p;
	for(int v : g[u]){
		if(v == p)continue;
		depth[v] = depth[u] + 1;
		go(v,u);
	}
}


ll A(ll &a,ll b){
	a += b;
	if(a >= mod)a -= mod;
	if(a < 0)a += mod;
	return a;
}
int n;
int root;

void dfs(int u,int p,int t){
	for(int v : g[u]){
		if(v == p)continue;
		dfs(v,u,!t);
		dp[u][root][t][1] += dp[v][root][!t][0];
	}
	if(dp[u][root][t][1] == 0)dp[u][root][t][0] = 1;
}

int dontuse;

pair<int,int> doit(int u,int p,int t){
	if(u == dontuse)return {0,!t};
	pair<int,int> res = {0,0};
	for(int v : g[u]){
		if(v == p)continue;
		auto cur = doit(v,u,!t);
		res.first += doit(v,u,!t).second;
	}
	if(res.first == 0)res.second++;
	return res;
}

int main(){
	fast
	ll d;
	cin>>n>>d;
	if(n == 2)cout << Pow(4,d) << '\n';
	else{
		g.resize(n+1);
		depth.resize(n+1);
		par.resize(n+1);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ll ans = 0;
		go(1,0);
		for(int i=1;i<=n;i++){
			root = i;
			dfs(i,0,0);
			dfs(i,0,1);
		}
		vector<int> candoit(n+1);
		for(int i=1;i<=n;i++){
			dontuse = i;
			if(doit(1,0,0).first > 0){
				candoit[i] = 1;
			}
		}
		// cerr << dp[2][1][0][1] << '\n';
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int can = 0;
				// cerr << i << ' ' << j << ' ' << candoit[i] << '\n';
				if(candoit[i]){
					A(ans,1);
					continue;
				}
				int t = depth[i]%2;
				if(t == 0){
					int cnt = (dp[j][j][1][0] > 0);
					for(int v : g[i]){
						if(v == par[i])continue;
						cnt += (dp[v][1][1][0] > 0);
					}
					if(cnt)A(ans,1);
				}else{
					int cnt = (dp[j][j][0][0] > 0);
					// if(i == 2 && j == 2)cerr << dp[j][j][0][0] << '\n';
					for(int v : g[i]){
						if(v == par[i])continue;
						cnt += (dp[v][1][0][0] > 0);
					}
					if(cnt == 0){
						A(ans,1);
					}
				}
				// return 0;
			}
		}
		cout << ans << '\n';
	}
}