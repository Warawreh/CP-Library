/*
Name: Centroid Decomposition
Description: Used to find paths with spicific attriputs by dividing the tree in the center
Note: If you want to find a path in a tree use Centroid if you want to find paths in a subtree use Sack.
Time: O(NLogN) since each node will be visited at most logN times
Space: O(N)
*/
vector<int> sz;
vector<bool> isCentroid;

void dfs(int u,int p){
   sz[u] = 1;
   for(auto &[v,d] : g[u]){
      if(v == p || isCentroid[v])continue;
      dfs(v,u);
      sz[u] += sz[v];
   }
}

void go1(int u,int p,int val){

   for(auto v : g[u]){
      if(v == p || isCentroid[v])continue;
   }

}

void decompose(int u){
   dfs(u,-1);
   int lst = -1,groupSize = sz[u];

   while(true){
      int nxt = -1;
      for(auto &[v,d] : g[u]){
         if(v == lst || isCentroid[v])continue;
         if(sz[v] * 2 > groupSize){//True at most once
            nxt = v;
            break;
         }
      }
      if(nxt == -1)break;
      lst = u;
      u = nxt;
   }

   isCentroid[u] = true;

   for(auto &[v,d] : g[u]){
      if(isCentroid[v])continue;
      go1(v,u,d);
      //Do work
   }

   for(auto &[v,d] : g[u]){
      if(isCentroid[v])continue;
      decompose(v);
   }
}