#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<int,ll>>> g;

struct LCA{
   vector<vector<ll>> par,len;
   vector<int> depth;
   vector<vector<pair<int,ll>>> g;
   int LOG;

   LCA(int log){init(log);}
   void init(int log){
      LOG = log;
      par = len = vector<vector<ll>>((1<<LOG),vector<ll>(LOG));
      depth = vector<int>((1<<LOG));
   }

   void setG(vector<vector<pair<int,ll>>> &G){
      g = G;
   }

   void dfs(int u,int p){
      for(auto &[v,w] : g[u]){
         if(v == p)continue;
         depth[v] = depth[u] + 1;
         par[v][0] = u;
         len[v][0] = w;
         for(int k=1;k<LOG;k++){
            par[v][k] = par[par[v][k-1]][k-1];
            len[v][k] = len[v][k-1] + len[par[v][k-1]][k-1];
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

vector<int> point,ans;

int dfs(int u,int p){

   int cur = 0;
   for(auto &[v , w] : g[u]){
      if(v == p)continue;
      cur += dfs(v,u);
   }
   ans[u] = cur;
   return cur + point[u];
}

void solve(){
   int n;
   cin>>n;

   g.clear();
   g.resize(n);
   point = ans = vector<int>(n , 0);

   vector<ll> x(n);
   for(int i=0;i<n;i++)cin>>x[i];

   for(int i=0;i<n-1;i++){
      int u,v,w;
      cin>>u>>v>>w;
      u--;v--;
      g[u].push_back({v , w});
      g[v].push_back({u , w});
   }

   LCA tree(20);
   tree.setG(g);
   tree.dfs(0,-1);

   for(int u=0;u<n;u++){

      point[u]++;
      int v = u;

      for(int k=19;k>=0;k--){
         if(tree.len[v][k] <= x[u]){
            x[u] -= tree.len[v][k];
            v = tree.par[v][k];
         }
      }

      // cerr << u << ' ' << v << '\n';
      point[v]--;

   }

   dfs(0,-1);

   for(int i=0;i<n;i++)
      cout << ans[i] << ' ';
   cout << '\n';
}

int main(){
   fast
   freopen("car.in","r",stdin);
   int t;
   cin>>t;
   while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/