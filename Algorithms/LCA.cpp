
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
