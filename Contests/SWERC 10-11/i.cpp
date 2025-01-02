#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,x,y;
vector<vector<pair<int,int>>> g;
vector<vector<int>> adj;
vector<int> keys,in,ret,fr,to,depth;
vector<vector<int>> par;
int T;

const int LOG =12;

void init(){	
	g.clear();
	g.resize(n);
	adj.clear();
	adj.resize(n);
	keys = vector<int>(k,0);
	in = fr = to = depth = vector<int>(n,0);
	ret= vector<int>(n,-1);
	T=0;
	par = vector<vector<int>>(n,vector<int>(LOG,0));
}

void dfs(int u,int p){
	fr[u] = ++T;
	for(auto &[v,d] : g[u]){
		if(v == p)continue;
		adj[u].push_back(v);

		depth[v] = depth[u] + 1;
		par[v][0] = u;

		for(int k=1;k<LOG;k++){
			par[v][k] = par[par[v][k-1]][k-1];
		}

		in[v]++;
		if(d != -1){
			adj[keys[d]].push_back(v);
			ret[v] = keys[d];
			in[v]++;
		}

		dfs(v,u);
	}
	to[u] = T;
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

int dist(int u,int v){
	return depth[u] + depth[v] - 2*depth[lca(u,v)];
}

void solve(){
	init();

	for(int i=0;i<k;i++){
		cin>>keys[i];
	}
	for(int i=0;i<n-1;i++){
		int u,v,nk;
		cin>>u>>v>>nk;
		if(nk == n)nk = -1;
		g[u].push_back({v,nk});
		g[v].push_back({u,nk});
	}

	dfs(x,-1);

	vector<int> q;
	q.push_back(x);
	int qh=0;
	vector<int> ans;
	vector<bool> vis(n);
	for(qh=0;qh<q.size();qh++){
		int u = q[qh];
		ans.push_back(u);
		if(u == y)break;
		if(vis[u])continue;
		vis[u] = 1;
		for(int v : adj[u]){
			in[v]--;
			if(in[v] == 0){
				if(ret[v] != -1){
					q.push_back(ret[v]);
				}
				q.push_back(v);
			}
		}
	}

	if(ans.size() && ans.back() == y){

		// for(int i=0;i<ans.size();i++)
		// 	cerr << ans[i] << ' ';
		// cerr << '\n';

		int at = x;
		vector<int> res = {at};
		for(int i=0;i<ans.size();i++){
			int nxt = ans[i];
			while(nxt != at){
				if(fr[nxt] >= fr[at] && fr[nxt] <= to[at]){

					int d = dist(nxt,at);
					at = kth(nxt,d-1);

				}else{
					at = par[at][0];
				}
				res.push_back(at);
			}
		}

		cout << res.size() - 1 << ":";
		for(int i : res)
			cout << ' ' << i;
		cout << '\n';

	}else cout << "Impossible\n";
}

int main(){
	fast
	while(1){
		cin>>n>>k>>x>>y;
		if(!n&&!k&&!x&&!y)break;
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/