/*
Name: DSU on trees (Sack) Small to large
Description: Solve subtree problems in a rooted tree using small to large technique 
Note: try to make the add operation constant. Also for maximum optimization don't use a function to add
just use a for loop from fr[u] to to[u].
Time: O(NLogN)
Space: O(N)
*/
typedef int T;
vector<T> cnt,sz;
vector<bool> big;

void calc(int u,int p){
   sz[u] = 1;
   for(int v : g[u]){
      if(v == p)continue;
      calc(v,u);
      sz[u] += sz[v];
   }
}

void add(int u,int p,T val){
   cnt[col[u]] += val;
   for(int v : g[u]){
      if(v == p || big[v])continue;
      add(v,u , val);
   }
}

void dfs(int u,int p,bool keep){
   int mx = -1,bigChild = -1;
   for(int v : g[u]){
      if(v == p)continue;
      if(sz[v] > mx){
         mx = sz[v];
         bigChild = v;
      }
   }
   for(int v : g[u]){
      if(v == p || v == bigChild)continue;
      dfs(v , u , 0);
   }
   if(bigChild != -1){
      dfs(bigChild , u , 1);
      big[bigChild] = 1;
   }
   add(u , p , 1);
   if(bigChild != -1){
      big[bigChild] = 0;
   }
   if(keep == 0)add(u , p , -1);
}