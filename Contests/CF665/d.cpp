#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
vector<vector<int>> g;
vector<ll> hv,sz;
int n;

void dfs(int u,int p){
	sz[u] = 1;
	for(int v : g[u]){
		if(v == p)continue;
		dfs(v,u);
		sz[u] += sz[v];
		hv.push_back(sz[v] * (n - sz[v]));
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		hv.clear();
		g.clear();
		sz.clear();
		sz.resize(n+1);
		g.resize(n+1);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		sort(all(hv));
		int m;
		cin>>m;
		vector<ll> p(max(m,n-1),1);
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		sort(all(p));
		// reverse(all(p));
		// reverse(all(hv));
		while(m > n-1){
			m--;
			ll x = p.back();
			p.pop_back();
			p.back() = (p.back() * x)%mod;
		}
		ll ans = 0;
		for(int i=0;i<n-1;i++){
			ans = (ans + (hv[i] * p[i])%mod)%mod;
		}
		cout << ans << '\n';
	}
}