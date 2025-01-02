#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2e5 + 5;

vector<vector<int>> g;
vector<vector<pair<ll,ll>>> aux;
ll ans = 0,tot = 0;
vector<bool> good;

vector<int> prime;
vector<bool> is_composite;

void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

vector<int> fr,to;
int DFS;

void dfs(int u,int p){
	fr[u] = ++DFS;
	for(int v : g[u]){
		if(v == p)continue;
		dfs(v,u);
	}
	to[u] = DFS;
}

struct LCA{
   vector<vector<int>> par;
   vector<int> depth;
   vector<vector<int>> g;
   int LOG;

   LCA(int log){init(log);}
   void init(int log){
      LOG = log;
      par = vector<vector<int>>((1<<LOG),vector<int>(LOG));
      depth = vector<int>((1<<LOG));
   }

   void setGraph(vector<vector<int>> &G){
   	g = G;
   }

   void addEdge(int u,int v){
      g[u].push_back(v);
      g[v].push_back(u);
   }

   void dfs(int u,int p){
      for(int v : g[u]){
         if(v == p)continue;
         depth[v] = depth[u] + 1;
         par[v][0] = u;
         for(int k=1;k<LOG;k++){
            par[v][k] = par[par[v][k-1]][k-1];
         }
         dfs(v,u);
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


   int dist(int u,int v){
      return depth[u] + depth[v] - 2*depth[lca(u,v)];
   }


};

const int mod = 998244353 ;
LCA lca(18);


ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}

ll inv6;

ll nC3(ll n){
	return (((n * (n - 1))%mod * (n - 2))%mod * inv6)%mod;
}

int calc(int u,int p){

	ll allDown = good[u];
	for(auto &[v , w] : aux[u]){
		if(v == p)continue;
		ll down = calc(v,u);


		ll cur = nC3(tot);
		if(down >= 3){
			cur = (cur - nC3(down) + mod)%mod;
		}
		if(tot - down >= 3){
			cur = (cur - nC3(tot - down) + mod)%mod;	
		}
		cur = (cur * w)%mod;

		ans = (ans + cur)%mod;

		allDown += down;
	}
	return allDown;
}

int buildAux(vector<int> cur){
	sort(all(cur) , [&](int u,int v){
		return fr[u] < fr[v];
	});

	vector<int> nodes = cur;

	for(int i=1;i<cur.size();i++){
		int u = cur[i];
		int v = cur[i-1];
		int l = lca.lca(u,v);

		nodes.push_back(l);
	}

	sort(all(nodes) , [&](int u,int v){	
		return fr[u] < fr[v];
	});
	nodes.resize(unique(all(nodes)) - nodes.begin());
	
	for(int u : nodes){
		aux[u].clear();
		good[u] = 0;
	}
	for(int u : cur)good[u] = 1;

	vector<int> st = {nodes[0]};
	for(int i=1;i<nodes.size();i++){

		int u = nodes[i];
		while(st.size() >= 2 && !(fr[st.back()] <= fr[u] && to[st.back()] >= fr[u])){
			int up = st[st.size() - 2];
			int down = st.back();
			aux[up].push_back({down , lca.depth[down] - lca.depth[up]});
			st.pop_back();
		}
		st.push_back(u);

	}

	while(st.size() >= 2){
		int up = st[st.size() - 2];
		int down = st.back();
		aux[up].push_back({down , lca.depth[down] - lca.depth[up]});
		st.pop_back();
	}

	return st[0];
}

int main(){
	fast

	inv6 = POW(6 , mod-2);
	sieve(600);

	int n;
	cin>>n;

	g.resize(n);
	fr = to = vector<int>(n,0);
	good = vector<bool>(n , 0);

	vector<vector<int>> nodes(nax);

	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		for(int p : prime){
			if(p > a)break;
			if(a % p == 0){
				nodes[p].push_back(i);
				while(a % p == 0)a /= p;
			}
		}
		if(a != 1){
			nodes[a].push_back(i);
		}
	}

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	

	lca.setGraph(g);
	lca.dfs(0,-1);
	dfs(0,-1);

	aux.resize(n);

	for(int i=2;i<nax;i++){

		vector<int> &cur = nodes[i];
		if(cur.size() < 3)continue;
		
		int root = buildAux(cur);
		tot = cur.size();
		calc(root , -1);

	}

	cout << ans << '\n';
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/