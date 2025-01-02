#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g, rg;
vector<bool> vis;
vector<int> order, component;

void dfs1(int u) {
    vis[u] = true;
    for (auto v : g[u])
        if (!vis[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    component.push_back(u);
    for (auto v : rg[u])
        if (!vis[v])
            dfs2(v);
}


struct DSU{

   vector<int> dsu,sz,rnk;

   void init(int n,int x){
      dsu = sz = rnk = vector<int> (n+x);
      iota(dsu.begin()+x,dsu.end(),x);
      fill(sz.begin(),sz.end(),1);
   }

   int find(int u){
      return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
   }

   bool merge(int u,int v){
      u = find(u);
      v = find(v);
      if(u == v)return false;
      if(sz[u] < sz[v])swap(u,v);
      // if(rnk[u] > rnk[v])swap(u,v);
      sz[u] += sz[v];
      // rnk[v] = rnk[u] + 1;
      dsu[v] = u;
      return true;
   }   
};


int main(){
    fast
    int n,m;
    cin>>n>>m;

    g.resize(n);
    rg.resize(n);
    DSU d;
    d.init(n,0);

    for(int i=0;i<m;i++){
    	int u,v;
    	cin>>u>>v;
    	u--;v--;
    	d.merge(u,v);
    	g[u].push_back(v);
    	rg[v].push_back(u);
    }
    set<int> st;
    for(int i=0;i<n;i++)
    	st.insert(d.find(i));

    vis = vector<bool>(n,0);
	for (int i = 0; i < n; i++)
	    if (!vis[i])dfs1(i);

	vis = vector<bool>(n,0);
	reverse(order.begin(), order.end());

	vector<int> id(n),sz;
	int at = 0;
	for (auto v : order)
	    if (!vis[v]) {
	        dfs2 (v);

	        sz.push_back(component.size());
	        for(int u : component){
	            id[u] = at;
	        }
	        at++;

	        component.clear();
	    }

	int ans = 0;
	vector<int> out(at,0),in(at,0);
	for(int i=0;i<n;i++){
		for(int v : g[i]){
			if(id[v]==id[i])continue;
			out[id[i]]++;
			in[id[v]]++;
		}
	}

	int ot=0,inn=0;
	for(int i=0;i<at;i++){
		if(out[i] == 0)ot++;
		if(in[i] == 0)inn++;
	}

	if(at == 1)cout << 0 << '\n';
	else cout << max(ot , inn) << '\n';

}
