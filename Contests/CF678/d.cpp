#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> sz,mx,sum,a;
vector<vector<int>> g;

void dfs(int u){

	for(int v : g[u]){
		dfs(v);
		sz[u] += sz[v];
		sum[u] += sum[v];
		mx[u] = max(mx[u] , mx[v]);
	}

	ll need = mx[u] * sz[u] - sum[u];
	sum[u] += a[u];
	a[u] -= min(a[u] , need);
	mx[u] += (a[u] + sz[u] - 1)/sz[u];
	// cerr << u << ' ' << sz[u] << ' ' << mx[u] << ' ' << sum[u] << '\n';

}

int main(){
	fast
	int n;
	cin>>n;
	sz = mx = sum = a = vector<ll>(n);
	g.resize(n);
	for(int v=1;v<n;v++){
		int u;
		cin>>u;
		u--;
		g[u].push_back(v);
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(g[i].size() == 0)sz[i] = 1;
	}
	dfs(0);
	cout << mx[0] << '\n';
}