#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct MINCUT{
	vector<vector<pair<ll,ll>>> g,rg;
	vector<int> parent,vis;
	vector<pair<int,int>> mincutedges;
	int ss,tt;
	int n;
	void init(int N){
		n = N+1;
		g = rg = vector<vector<pair<ll,ll>>> (n+1);
		parent = vis = vector<int> (n+1,-1);
	}

	void add_edge(int u,int v,ll w){
		g[u].push_back({v,w});
	}
 
	void dfs(int u){ 
		if(u == tt)return;
		vis[u] = 1; 
		// cerr << u << ":\n";
		for (pair<ll,ll> c : rg[u]) {
			ll v = c.first;
			ll w = c.second;
			// if(w != 1e18)vis[u] = 1;
			// cerr << u << ' ' << v << ' ' << w << ' ' << vis[v] << '\n';
			if (w && !vis[v]){
				dfs(v); 
			}
		}
	} 
 
	int bfs(int S, int T) { 
		// cerr << S << '\n';
		fill(vis.begin(),vis.end(),0);
		queue <int> q; 
		q.push(S); 
		vis[S] = 1;
		parent[S] = -1;
		while (q.size()){ 
			int u = q.front(); 
			// cerr << u << ' ';
			q.pop();
			for (pair<ll,ll> c : rg[u]) {
				ll v = c.first;
				ll w = c.second;
				if(parent[u] == S && v == T)continue;
				// cerr << u << ' ' << v << ' ' << w << '\n';
				// if(vis[v] && parent[v] == S && w > 0)parent[v] = u;
				if(vis[v] || w <= 0)continue;
				q.push(v);
				parent[v] = u; 
				vis[v] = 1; 
			} 
		}
		// cerr << '-' << S << '\n';
		// exit(0);
		return vis[T]; 
	} 
	void minCut(int S, int T) {
		ss = S;
		tt = T;
		for(int i=0;i<n;i++){
			rg[i] = g[i];
		}
 	
		while (bfs(S,T)) { 
			ll path_flow = 1e18;
			// cerr << 1 << '\n'; 
			for(int v=T; v!=S ;v=parent[v]){ 
				int u = parent[v]; 
				int at = lower_bound(all(rg[u]) , make_pair((ll)v,(ll)-1e9)) - rg[u].begin();
				assert(rg[u][at].first == v);
				// cerr << v << ' ' << u << ' ' << rg[u][at].second << '\n';
				path_flow = min(path_flow, rg[u][at].second); 
			} 
			// cerr << path_flow << '\n';
			// cerr << -1 << '\n';
			for(int v=T; v!=S; v=parent[v]){ 
				int u = parent[v];
				int at = lower_bound(all(rg[u]) , make_pair((ll)v,(ll)-1e9)) - rg[u].begin();
				rg[u][at].second -= path_flow; 
				// cerr << u << ' ' << v << ' ' << rg[u][at].second << ' ' << path_flow << '\n';
				at = lower_bound(all(rg[v]) , make_pair((ll)u,(ll)-1e9)) - rg[v].begin();
				// cerr << v << ' ' << parent[v] << '\n';
				if(at < rg[v].size())
					rg[v][at].second += path_flow; 
				else
					rg[v].push_back({u,path_flow});
				// cerr << v << ' ' << parent[v] << '\n';
				// if(v == parent[v])break;
			}
			// break;
		}
		fill(vis.begin(),vis.end(),0);
		dfs(S); 
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (pair<ll,ll> x : g[i]) {
				int j = x.first;
				// cerr << vis[i] << ' ' << vis[j] << '\n';
				if (vis[i] && !vis[j]) {
					mincutedges.push_back({i,j});
					// cerr << x.second << ' ' << i << ' ' << j << '\n';
					if(x.second <= 1e9)ans += x.second;
				}
			}
		}
		cout << ans << '\n';	
	} 
 
};

MINCUT g;

int main(){
	fast
	int n,m;
	cin>>n>>m;
	g.init(n+3);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x){
			int a = i;
			int b = (i+1)%n;
			if(a > b)swap(a,b);
			g.add_edge(a,b,x);
			// g.add_edge(b,a,x);
		}
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a > b)swap(a,b);
		a--;b--;
		g.add_edge(n,a,(ll)1e18);	
		g.add_edge(b,n+1,(ll)1e18);
	}
	for(int i=0;i<=n+1;i++){
		sort(all(g.g[i]));
		sort(all(g.rg[i]));
	}

	g.minCut(n,n+1);
}