/*
Name: Heavy Light Decomposition
Description: Update and query paths in trees in log time
Time: O(N) to prep the tree and O(TLogN) for a query (T is the time for the query)
Space: O(N)
Note:
when treversing a light edge (nxt[u] == u) use constant operations to half the take taken
*/

struct HLD{
    vector<int> sz,fr,to,nxt,depth;
    int DFS = 0;
    vector<int> par;
    vector<vector<int>> g;

    int lca(int x, int y) {
        for (; nxt[x] != nxt[y]; y = par[nxt[y]])
            if (depth[nxt[x]] > depth[nxt[y]]) swap(x,y);
        return depth[x] < depth[y] ? x : y;
    }
     
     
    void initHLD(int N){
        n = N;
        sz = depth = fr = to = nxt = vector<int>(n,0);
        par = vector<int>(n,-1);
    }
    
    void setG(vector<vector<int>> &G){g = G;}
     
     
    void dfs_sz(int u,int P) {
        sz[u] = 1;
        par[u] = P;
        if(P != -1){
            g[u].erase(find(all(g[u]), P));
            depth[u] = depth[P] + 1;
        }else depth[u] = 0;

        for(auto &v: g[u]) {        
            dfs_sz(v,u);
            sz[u] += sz[v];
            if(sz[v] > sz[g[u][0]]) {
                swap(v, g[u][0]);
            }
        }
    }
     
    void dfs_hld(int u,int P) {
        fr[u] = ++DFS;

        for(auto &v: g[u]){
            nxt[v] = (v == g[u][0] ? nxt[u] : v);
            dfs_hld(v,u);
        }
        to[u] = DFS;
    }

     
    int findPath(int u,int P){
        if(u == P)return tmp[u];
        int res = 0;
        while(u != -1 && nxt[u] != nxt[P]) {
            if(nxt[u] == u)res = max(res , tmp[u]);
            else res = max(res, get(fr[nxt[u]], fr[u]));

            u = par[nxt[u]];
        }
        res = max(res, get(fr[P], fr[u]));
        return res;
    }
     
    int Find(int u,int v){
        int l = lca(u,v);
        return max(findPath(u,l) , findPath(v , l));
    }
     
     
    void prep(){
        dfs_sz(0,-1);
        dfs_hld(0,-1);
    }
     
};