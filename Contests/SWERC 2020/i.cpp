#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ans = 0;
vector<vector<int>> g;

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

int n,m;
int bfs(int u){
	vector<int> dist(n,-1);
	dist[u] = 0;
	vector<int> q;
	q.push_back(u);
	vector<int> far;

	for(int qh=0;qh<q.size();qh++){
		int u = q[qh];
		if(far.empty() || dist[u] > dist[far.back()]){
			far = {u};
		}else if(dist[u] == dist[far.back()])far.push_back(u);

		for(int v : g[u]){
			if(dist[v] != -1)continue;
			dist[v] = dist[u] + 1;
			q.push_back(v);
		}
	}
	ans = max(ans , dist[far.back()]);
	int chose = uniform_int_distribution<int>(0, far.size()-1)(rng);
	return far[chose];
}

int main(){
    fast
    cin>>n>>m;
    g.resize(n);
    DSU d;
    d.init(n,0);
    for(int i=0;i<m;i++){
    	int u,v;
    	cin>>u>>v;
    	u--;v--;
    	// u = i;v = (i+1)%n;
    	d.merge(u,v);
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
    	if(d.find(i) != d.find(0)){
    		cout << -1 << '\n';
    		return 0;
    	}
    }

    int tms = (int)1e7 / (int)n;
    int cur = 0;
    for(int it=0;it<tms;it++){
    	cur = bfs(cur);
    }

	cout << ceil(log2(ans)) << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/