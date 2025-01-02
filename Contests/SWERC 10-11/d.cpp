#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int SZ> struct FORD{
      	ll g[SZ][SZ],rg[SZ][SZ];
      	int parent[SZ];
      	bool vis[SZ];
      	vector<pair<int,int>> mincutedges;
      	void addEdge(int u,int v,ll w){
                	g[u][v] = w;
      	}
 
      	void dfs(int u){
                	vis[u] = 1;
                	for (int v = 0; v < SZ; v++)
                          	if (rg[u][v] && !vis[v])
                                    	dfs(v);
      	}
 
      	int bfs(int S, int T) {
                	memset(vis, 0, sizeof(vis));
                	queue <int> q;
                	q.push(S);
                	vis[S] = 1;
                	parent[S] = -1;
                	while (q.size()){
                          	int u = q.front();
                          	q.pop();
                          	for (int v=0;v<SZ;v++){
                                    	if(vis[v] || rg[u][v] <= 0)continue;
                                    	q.push(v);
                                    	parent[v] = u;
                                    	vis[v] = 1;
                          	}
                	}
                	return vis[T];
      	}
      	ll minCut(int S, int T) {
                	for(int i=0;i<SZ;i++)
                          	for(int j=0;j<SZ;j++)
                                    	rg[i][j] = g[i][j];
 					ll flow=0;
                	while (bfs(S,T)) {
                          	ll path_flow = 1e18;
                          	for(int v=T; v!=S ;v=parent[v]){
                                    	int u = parent[v];
                                    	path_flow = min(path_flow, rg[u][v]);
                          	}
                          	flow += path_flow;
                          	for(int v=T; v!=S; v=parent[v]){
                                    	int u = parent[v];
                                    	rg[u][v] -= path_flow;
                                    	rg[v][u] += path_flow;
                          	}
                	}
                	return flow;
      	}
};
 



int main(){
	fast
	while(1){
		int t,p;
		cin>>t>>p;
		if(t==0 && p == 0)break;
		int sum = 0;
		int S = t+p+1;
		int T = S+1;

		FORD<200> flow;

		ll s1=0,s2=0;
		for(int i=0;i<t;i++){
			for(int j=0;j<p;j++)
				flow.addEdge(i,j+t,1);
		}

		bool good = true;
		for(int i=0;i<t;i++){
			int a;
			cin>>a;
			if(a > p)good = false;
			a = p-a;
			s1+=a;
			flow.addEdge(S,i,a);
		}
		for(int i=0;i<p;i++){
			int a;
			cin>>a;
			if(a > t)good = false;
			a = t-a;
			s2+=a;
			flow.addEdge(t+i,T,a);
		}

		int mf = flow.minCut(S,T);
		cerr << mf << ' ' << s1 << ' ' << s2 << '\n';
		// if(mf != s1 || s1 != s2 || !good){
		// 	cout << "Impossible\n";
		// }else{
		// 	vector<string> s(t,string(p,'Y'));
		// 	for(int u=t;u<t+p;u++){
		// 		for(int i=0;i<flow.g[u].size();i++){
		// 			int v = flow.g[u][i].to;
		// 			if(v < t){
		// 				int f = flow.g[u][i].f;
		// 				// cerr << v << ' ' << u-t << ' ' << f << '\n';
		// 				if(f)s[v][u-t] = 'N';
		// 				else s[v][u-t] = 'Y';
		// 			}
		// 		}
		// 	}

		// 	for(int i=0;i<t;i++)
		// 		cout << s[i] << '\n';
		// }
		// cout << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/