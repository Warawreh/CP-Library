#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct BRE{
	/*
		Put in the begin of the code
			init() 
	*/
	int n,T,c;
	vector<int> idx,low,art;
	vector<vector<int>> g;
	vector<pair<int,int>> bridges;
	int bad = 0;
	void init(int N){// Number of vertexes in graph
		n = N;
		idx = low = vector<int> (n+1,0);
		g.resize(n+1,{});
	}
	void search_for_ba(int u,int p){
		idx[u] = low[u] = ++T;
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i];
			if(!idx[v]){
				if(!p)bad++;
				if(!p)c++;
				search_for_ba(v,u);
				low[u] = min(low[u],low[v]);
				if(low[v] >= idx[u] && p)art.push_back(u);
			}else if(v != p)low[u] = min(low[u],idx[v]);
		}
	}
	void search(){
		for(int i=1;i<=n;i++){
			if(idx[i] == 0){ // searh for bridges in all unvisted graphs
				bad = 0;
				search_for_ba(i,0);
				if(bad != 1)art.push_back(i);
				break;
			}
		}
	}
};

vector<bool> vis;
map<int,bool> bad;
vector<vector<int>> g;
set<int> w;
ll cnt=0;

void dfs(int u){
	vis[u] = true;
	cnt++;
	for(int v : g[u]){
		if(bad[v])w.insert(v);
		if(vis[v] || bad[v])continue;
		dfs(v);
	}
}
int main() {
	fast
	int T=0;
	while(1){
		T++;
		int m;
		cin>>m;
		if(!m)break;
		vector<pair<int,int>> edg(m);
		int n=0;
		for(pair<int,int> &a : edg){
			cin>>a.first>>a.second;
			n = max({n,a.first,a.second});
		}
		bad.clear();
		vis = vector<bool> (n+1,0);
		BRE graph;
		graph.init(n);
		for(pair<int,int> a : edg){
			graph.g[a.first].push_back(a.second);
			graph.g[a.second].push_back(a.first);
		}
		g = graph.g; 
		graph.search();
		for(int x : graph.art){
			// cerr << x << '\n';
			bad[x] = true;
		}
		ull ans = 1,need=0;
		for(int i=1;i<=n;i++){
			if(vis[i] || bad[i])continue;
			// cerr << i << ' ' << bad[i] << '\n';
			w.clear();
			cnt=0;
			dfs(i);
			if(w.size() == 1){
				need++;
				ans = ans * cnt;
			}
		}
		// cerr << need << '\n';
		cout << "Case " << T << ": "; 
		if(need >= 2)cout << need << ' ' << ans << '\n';
		else cout << 2 << ' ' << n * (ull)(n-1) / 2 << '\n';
	}
}