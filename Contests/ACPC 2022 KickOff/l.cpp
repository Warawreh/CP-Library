#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DINIC{
	const ll oo = 1e18; 
	struct Edge {
		ll to,rev,f,cap;
		ll flow() { return max(cap - f, 0LL); }
	};
	vector<vector<Edge>> g;
	vector<int> cost,q;
	int S,T;
	void init(int n){
		g.resize(n+1);cost.resize(n+1);q.resize(n+1);
	}
	void addEdge(int u, int v, ll cap){
		Edge a = {v,(int)g[v].size(), 0, cap};
		Edge b = {u,(int)g[u].size(), 0, 0};
		g[u].push_back(a);
		g[v].push_back(b);
	}
	bool bfs() {
		fill(cost.begin(),cost.end(),-1);
		cost[S] = 0;
		int qt = 0;
		q[qt++] = S;
		for(int qh=0;qh<qt;qh++){
			int u = q[qh];
			for(int j=0;j<(int)g[u].size();j++) {
				Edge &e = g[u][j];
				int v = e.to;
				if(cost[v] == -1 && e.f < e.cap) {
					cost[v] = cost[u] + 1;
					q[qt++] = v;
				}
			}
		}
		return cost[T] != -1;
	}

	ll dfs(int u,ll f){
		if(u == T)return f;
		for(int i=0;i<(int)g[u].size();i++){
			Edge &e = g[u][i];
			if (e.cap <= e.f) continue;
			int v = e.to;
			if (cost[v] == cost[u] + 1) {
				ll df = dfs(v, min(f, (e.cap - e.f)*1ll));
				if (df > 0) {
					e.f += df;
					g[v][e.rev].f -= df;
					return df;
				}
			}
		}
		return 0;
	}
	ll maxFlow(int s, int t){
		S = s;
		T = t;
		ll res = 0;
		while (bfs()) {
			while(ll d = dfs(S,oo)){
				res += d;
			}
		}
		return res;
	}
};

void solve(){
	string s;
	int m;
	cin>>s>>m;
	vector<int> l(26);
	vector<vector<int>> edges(26,vector<int>(26));
	for(int i=0;i<m;i++){
		char a,b;
		cin>>a>>b;
		a -= 'a';b -= 'a';
		edges[a][b]++;
	}
	int n = s.size();
	for(int i=0;i<n;i++)l[s[i] - 'a']++;
	

	bool can = false;
	for(int T=0;T<26;T++){
		DINIC graph;
		graph.init(30);
		int S = 26;
		for(int i=0;i<26;i++){
			if(l[i]){
				graph.addEdge(S,i,l[i]);
			}
			for(int j=0;j<26;j++){
				if(i == j || !edges[i][j])continue;
				graph.addEdge(i,j,edges[i][j]);
			}
		}

		if(graph.maxFlow(S,T) == n){
			can = true;
			break;
		}
	}
	cout << (can ?"YES\n" :"NO\n");
}

int main(){
	fast
	freopen("same.in","r",stdin);	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/