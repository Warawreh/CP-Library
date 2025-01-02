#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LOG = 19;
vector<vector<int>> g;
int par[(1<<LOG)][LOG],depth[(1<<LOG)],sz[(1<<LOG)];

void dfs(int u,int p){
	sz[u] = 1;
	for(int v : g[u]){
		if(v == p)continue;
		depth[v] = depth[u] + 1;
		par[v][0] = u;
		for(int k=1;k<LOG;k++){
			par[v][k] = par[par[v][k-1]][k-1];
		}
		dfs(v,u);
		sz[u] += sz[v];
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

int main(){
	fast
	int n,q;
	cin>>n>>q;
	g.resize(n);
	for(int i=1;i<n;i++){
		int p;
		cin>>p;
		p--;
		g[p].push_back(i);
		g[i].push_back(p);
	}
	dfs(0,-1);
	while(q--){
		int a,b;
		cin>>a>>b;
		a--;b--;
		int l = lca(a,b);
		int dist = depth[a] + depth[b] - 2 * depth[l];

		// cerr << a << ' ' << b << ' ' << l << ' ' << dist << ' ' << tmp << ' ' << sz[kth(a,dist)] << '\n';
		if(depth[b] < depth[a]){//target higher
			int tmp = dist;
			dist /= 2;
			int to = kth(b,dist);
			int stop = kth(a,dist);


			// cerr << to << ' ' << stop << '\n';
			// cerr << sz[to] - sz[stop] << ' ' << tmp << '\n';
			if(sz[to] - sz[stop] > dist + 1){
				cout << "yes\n";
			}else{
				cout << "no\n";
			}
		}else{
			dist--;
			int tmp = dist;
			dist /= 2;
			int to = kth(b,dist);
			// cerr << to << ' ' << dist << '\n';
			if(sz[to] > dist + 1){
				cout << "yes\n";
			}else{
				cout << "no\n";
			}
		}
	}
}