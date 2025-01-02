#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> dsu,sz,rnk;
vector<vector<pair<int,int>>> g;
vector<int> color;

void init(int n,int x){
	dsu = sz = rnk = vector<int> (n+x);
	iota(dsu.begin()+x,dsu.end(),x);
	fill(sz.begin(),sz.end(),1);
}

int find(int u){
	return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
}

void merge(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[u] < sz[v])swap(u,v); // enable for fast dsu
	// if(rnk[u] > rnk[v])swap(u,v);
	sz[u] += sz[v];
	rnk[v] = rnk[u] + 1;
	dsu[v] = u;
}

set<int> st;

void dfs(int u,int p,int t){
	if(t == -1){
		for(pair<int,int> c : g[u])st.erase(c.second);
		color[u] = *st.begin();
		for(pair<int,int> c : g[u])st.insert(c.second);
	}else{
		color[u] = t;
	}
	// cerr << u << ' ' << p << ' ' << t << '\n';

	for(pair<int,int> c : g[u]){
		int v = c.first;
		int w = c.second;
		if(v == p)continue;
		if(w == color[u])dfs(v,u,-1);
		else dfs(v,u,w);
	}

}

int main(){
	fast
	int n,m;
	cin>>n>>m;
	color.resize(n);
	for(int i=1;i<=n;i++)st.insert(i);
	g.resize(n);
	init(n,0);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		if(find(u) != find(v)){
			g[u].push_back({v,w});
			g[v].push_back({u,w});
			// cerr << u << ' ' << v << '\n';
			merge(u,v);
		}
	}
	dfs(0,-1,-1);
	for(int c : color)
		cout << c << '\n';
}