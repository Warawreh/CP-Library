#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct MINCUT{
	vector<vector<ll>> g,rg;
	vector<int> parent,vis;
	vector<pair<int,int>> mincutedges;
	int n;
	void init(int N){
		n = N+1;
		g = rg = vector<vector<ll>> (n+1,vector<ll> (n+1));
		parent = vis = vector<int> (n+1);
	}

	void add_edge(int u,int v,ll w){
		g[u][v] = w;
	}
 
	void dfs(int u){ 
		vis[u] = 1; 
		for (int v = 0; v < n; v++) 
			if (rg[u][v] && !vis[v]) 
				dfs(v); 
	} 
 
	int bfs(int S, int T) { 
		fill(vis.begin(),vis.end(),0);
		queue <int> q; 
		q.push(S); 
		vis[S] = 1;
		parent[S] = -1;
		while (q.size()){ 
			int u = q.front(); 
			q.pop();
			for (int v=0;v<n;v++){
				if(vis[v] || rg[u][v] <= 0)continue;
				q.push(v);
				parent[v] = u; 
				vis[v] = 1; 
			} 
		} 
		return vis[T]; 
	} 
	void minCut(int S, int T) {
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				rg[i][j] = g[i][j]; 
 
		while (bfs(S,T)) { 
			ll path_flow = 1e18; 
			for(int v=T; v!=S ;v=parent[v]){ 
				int u = parent[v]; 
				path_flow = min(path_flow, rg[u][v]); 
			} 
			for(int v=T; v!=S; v=parent[v]){ 
				int u = parent[v];
				rg[u][v] -= path_flow; 
				rg[v][u] += path_flow; 
			} 
		}
		fill(vis.begin(),vis.end(),0);
		dfs(S); 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				if (vis[i] && !vis[j] && g[i][j]) {
					mincutedges.push_back({i,j});
				}
	} 
 
};

const int N = 1e4 + 10;

vector<int> g[2*N],s;
int ans[2*N];
int n,m,idx[2*N],DFS,cmp,gid[2*N],gh[2*N],low[2*N],gsz[2*N];
bool vis[2*N];
 
void dfs(int u){
	idx[u] = low[u] = ++DFS;
	s.push_back(u);
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i];
		if(!idx[v])dfs(v);
		if(vis[v])low[u] = min(low[u],low[v]);
	}
	if(low[u] == idx[u]){
		gh[cmp] = u;
		while(1){
			int v = s.back();
			s.pop_back();
			vis[v] = 0;
			gid[v] = cmp;
			gsz[cmp]+=(v < m);
			if(v==u)break;
		}
		cmp++;
	}
}
 
int NOT(int x){
	if(x >= m)return x-m;
	return x+m;
}
 

short dp[N][N/2];

short calc(int i,int sum){
	// cout << i << ' ' << sum << ' ' << gsz[i] << '\n';
	if(i == cmp){
		return (sum == m/2);
	}
	if(sum > m/2)return 0;
	short &ret = dp[i][sum];
	if(ret != -1)return ret;
	ret = 0;
	if(i < gid[NOT(gh[i])]){
		ret = calc(i + 1,sum + gsz[gid[NOT(gh[i])]]) | calc(i + 1,sum + gsz[i]);
	}else{
		ret = calc(i + 1,sum);
	}
	return ret;
}

void build(int i,int sum){
	if(i == cmp){
		return;
	}
	if(i < gid[NOT(gh[i])]){
		if(calc(i,sum) == calc(i + 1,sum + gsz[i])){
			ans[i] = 1;
			ans[gid[NOT(gh[i])]] = 0;
			build(i + 1,sum + gsz[i]);
		}else{
			ans[i] = 0;
			ans[gid[NOT(gh[i])]] = 1;
			build(i + 1,sum + gsz[gid[NOT(gh[i])]]);
		}
	}else{
		build(i + 1,sum);
	}
}

int main(){
	fast
	cin>>m>>n;
	if(m % 2){
		cout << -1 << '\n';
		return 0;
	}
	for(int i=0;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(NOT(v));
		g[v].push_back(NOT(u));
		g[NOT(u)].push_back(v);
		g[NOT(v)].push_back(u);
	}
	for(int i=0;i<2*m;i++)
		if(!idx[i])
			dfs(i);
	for(int i=0;i<m;i++)
		if(gid[i] == gid[NOT(i)]){
			cout << "-1\n";
			return 0;
		}
	memset(ans,-1,sizeof(ans));
	memset(dp,-1,sizeof(dp));
	// for(int i=0;i<cmp;i++)
	// 	cerr << gsz[i] << ' ';
	if(calc(0,0) == 0){
		cout << -1 << '\n';
		return 0;
	}
	build(0,0);
	int e = 0;
	for(int i=0;i<m;i++){
		assert(ans[gid[i]] != -1);
		e += ans[gid[i]];
	}
	if(e != m/2){
		while(1);
	}
	vector<int> a(m);
	int ate = 0;
	int atb = 1;
	for(int i=0;i<m;i++){
		if(ans[gid[i]]){
			a[ate] = i + 1;
			ate += 2;
		}else{
			a[atb] = i + 1;
			atb += 2;
		}
		// cerr << ans[gid[i]] << '\n';
	}
	for(int i : a)
		cout << i << ' ';
	puts("");
}
