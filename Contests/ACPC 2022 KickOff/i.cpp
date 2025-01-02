#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct BRE{
    int n,T,c;
    vector<int> idx,low,art;
    vector<vector<int>> g;
    vector<pair<int,int>> bridges;
    map<pair<int,int>,int> edgs;
    int cnt;
    vector<int> comps;
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
        cnt++;
        int children = 0;
        for(int v : g[u]){
            if (v == p) continue;

            if(!idx[v]){
                search_for_ba(v,u);
                low[u] = min(low[u],low[v]);

                if(low[v] > idx[u]){
                    if(edgs[{u,v}] + edgs[{v,u}] < 2)
                        bridges.push_back({u,v});
                }
                if(low[v] >= idx[u] && p!=-1)art.push_back(u);
                children++;
            }else low[u] = min(low[u],idx[v]);
        }
        if(p == -1){
            for(int i=1;i<children;i++)art.push_back(u);
        }
    }
    void search(){
        for(int i=0;i<n;i++){
            if(idx[i] == 0){ // searh for bridges in all unvisted graphs
                cnt = 0;
                search_for_ba(i,-1);
                comps.push_back(cnt);
            }
        }
    }
};

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	BRE g(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g.addEdge(u,v);
	}
	g.search();

    vector<pair<int,int>> art;
    sort(all(g.art));


	for(int i=0;i<g.art.size();i++){
		if(art.empty() || art.back().first != g.art[i])art.push_back({g.art[i] , 1});
        else art.back().second++;
	}
    sort(all(art));
    reverse(all(art));
    int extra = 0;
    if(k < art.size())extra = art[k].second;
    else{
        k -= art.size();
        sort(all(g.comps));
        int sum = 0;
        for(int i=1;i<g.comps.size();i++)sum += g.comps[i];
        if(g.comps[0] == 1 && k >= sum)extra--;
    }
	cout << g.comps.size() + extra << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/