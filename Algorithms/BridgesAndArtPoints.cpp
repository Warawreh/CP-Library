/*
Name: Bridges and Articlation points
Description: find bridges and articlation points in undircated graph
Time: O(NLogN) if there are multiedges and O(N) if not (u -> v, v -> u) remove map if needed
Space: O(N) multiplied with a constants
*/
struct BRE{
    int n,T,c;
    vector<int> idx,low,art;
    vector<vector<int>> g;
    vector<pair<int,int>> bridges;
    map<pair<int,int>,int> edgs;

    BRE(int N){
        init(N);
    }

    void init(int N){// Number of vertexes in graph
        n = N;
        idx.resize(n+1);low.resize(n+1);g.resize(n+1);
    }

    void addEdge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
        edgs[{u,v}]++;
    }

    void initEdges(vector<vector<int>> G){
        g = G;
    }

    void search_for_ba(int u,int p){
        idx[u] = low[u] = ++T;
        for(int v : g[u]){

            if(!idx[v]){
                search_for_ba(v,u);
                low[u] = min(low[u],low[v]);

                if(low[v] > idx[u]){
                    if(edgs[{u,v}] + edgs[{v,u}] < 2)
                        bridges.push_back({u,v});
                }
                if(low[v] >= idx[u])art.push_back(u);
            }else if(v != p)low[u] = min(low[u],idx[v]);
        }
    }
    void search(){
        for(int i=0;i<n;i++){
            if(idx[i] == 0){ // searh for bridges in all unvisted graphs
                search_for_ba(i,-1);
            }
        }
    }
};