#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
vector<int> p,h,sz;
bool good;

void go(int u,int par){
	sz[u] = p[u];
	for(int v : g[u]){
		if(v == par)continue;
		go(v,u);
		sz[u] += sz[v];
	}
}

pair<int,int> dfs(int u,int par){
	if((h[u] + sz[u]) % 2){
		good = false;
	}
	pair<int,int> d = {(h[u] + sz[u]) / 2 , sz[u] - (h[u] + sz[u]) / 2};
	if(d.first < 0 || d.second < 0)good = false;
	// cerr << u << ' ' << d.first << ' ' << d.second << '\n';
	pair<int,int> he = d;
	pair<int,int> tot = {0,0};
	bool leaf = true;
	for(int v : g[u]){
		if(v == par)continue;
		leaf = false;
		pair<int,int> cur = dfs(v,u);
		tot.first += cur.first;
		tot.second += cur.second;

	}
	if(!leaf){
		he.first -= tot.first;
		he.second -= tot.second;
		// cerr << u  << '\n';
		// cerr << tot.first << ' ' << tot.second << '\n';
		// cerr << d.first << ' ' << d.second << '\n';
		// cerr << he.first << ' ' << he.second << '\n';
		if(tot.first + tot.second + p[u] != d.first + d.second){
			good = false;
		}
		if(tot.first > d.first || tot.second < d.second - he.second){
			good = false;
		}
	}

	return d;
}

void solve(){
	int n,m;
	cin>>n>>m;

	{
		good = true;
		g.clear();
		h.clear();	
		p.clear();
		sz.clear();
		sz.resize(n+1);
		g.resize(n+1);
		p.resize(n+1);
		h.resize(n+1);
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	go(1,0);
	dfs(1,0);
	cout << (good ? "YES\n" : "NO\n");
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}