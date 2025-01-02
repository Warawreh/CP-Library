#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
vector<vector<int>> par;
vector<int> DFS,depth,points;
int T;
int LOG = 1;

void buildLCA(int u,int p){
	DFS[u] = ++T;
	for(int v : g[u]){
		if(v == p)continue;
		depth[v] = depth[u] + 1;
		par[v][0] = u;
		for(int k=1;k<LOG;k++){
			par[v][k] = par[par[v][k-1]][k-1];
		}
		buildLCA(v,u);
	}
}

int kth(int u,int dist){
	for(int k=LOG-1;k>=0;k--){
		if(dist >= (1<<k)){
			dist -= (1<<k);
			u = par[u][k];
		}
	}
	return u;
}

int lca(int u,int v){
	if(depth[u] < depth[v])swap(u,v);
	assert(depth[u] - depth[v] >= 0);
	u = kth(u , depth[u] - depth[v]);
	if(u == v)return u;
	for(int k=LOG-1;k>=0;k--){
		if(par[u][k] != par[v][k]){
			u = par[u][k];
			v = par[v][k];
		}
	}
	return par[u][0];
}

int ans = 0;

int dfs(int u,int p){
	int cur = points[u];
	for(int v : g[u]){
		if(v == p)continue;
		cur += dfs(v,u);
	}
	if(cur == 0)ans++;
	return cur;
}

void solve(){

	int n;
	cin>>n;
			
	ans = 0;
	LOG = 1;
	{
		int tmp = n;
		while(tmp){
			LOG++;
			tmp /= 2;
		}
	}
	T = 0;
	par = vector<vector<int>>((1<<LOG),vector<int>(LOG,0));
	DFS = points = depth = vector<int>(n,0);
	g = vector<vector<int>>(n);

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	buildLCA(0,-1);
	vector<vector<pair<int,int>>> gr(n);
	for(int i=0;i<n;i++){
		int f;
		cin>>f;
		f--;
		gr[f].push_back({DFS[i],i});
	}
	for(int i=0;i<n;i++){
		sort(all(gr[i]));
		for(int j=1;j<gr[i].size();j++){
			int u = gr[i][j-1].second;
			int v = gr[i][j].second;
			int l = lca(u,v);
			points[u]++;
			points[v]++;
			points[l]-=2;
		}
	}
	dfs(0,-1);
	// assert(ans >= 0);
	cout << ans - 1 << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}