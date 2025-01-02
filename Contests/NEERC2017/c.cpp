#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
vector<int> sz;
vector<pair<int,int>> a;

void dfs(int u,int p){
	sz[u] = 1;
	// cerr << u << ' ' << p << '\n';
	for(int v : g[u]){
		if(v == p)continue;
		// cerr << u << ' ' << v << ' ' << p << '\n';
		dfs(v,u);
		sz[u] += sz[v];
	}
}

int n;
void go(int u,int p,int x,int y){
	a[u] = {x,y};
	int best = -1;
	for(int v : g[u]){
		if(v == p)continue;
		if(best == -1 || sz[v] > sz[best])best = v;
	}
	if(best == -1)return;
	go(best , u , x + (sz[u] - sz[best] - 1) + 1,y);
	int at = x;
	for(int v : g[u]){
		if(p == v)continue;
		if(v == best)continue;
		go(v , u , at , y+1);
		at += sz[v];
	}
}

int main(){
	fast
	cin>>n;	
	g.resize(n);
	sz.resize(n);
	a.resize(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,-1);
	// return 0;
	go(0,-1,1,1);
	map<pair<int,int>,bool> mp;
	for(auto i : a){
		assert(i.first <= (int)1e6);
		assert(i.second <= 20);
		assert(mp[i] == 0);
		mp[i] = true;
		cout << i.first << ' ' << i.second << '\n';
	}
}