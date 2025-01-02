#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

vector<int> fr,to,gr;
int T;
vector<vector<int>> g;

struct edge{
	int u,v;
	ll w;
	edge(){}

	void read(){
		cin>>u>>v>>w;
	}
	bool operator<(const edge &rhs){
		return w < rhs.w;
	}
};

void dfs(int u,int p,int gg){
	assert(fr[u] == 0);
    gr[u] = gg;
    fr[u] = ++T;

    for(int &v : g[u]){
        if(v == p)continue;
        dfs(v,u,gg);
    }
    to[u] = T;
}

void solve(){
    int m;
    cin>>m;

    fr = to = gr = vector<int>(n);
    g.resize(n);
    vector<edge> ed(m);

    for(int i=0;i<m;i++){
        ed[i].read();
    }
    sort(all(ed));
    ll res = 1e18;
    set<int> chosn;

    for(int i=0;i<m;i++){
        int u = ed[i].u;
        int v = ed[i].v;
	    // cerr << i << '\n';

        assert(chosn.size() <= n-1);

        for(int j=0;j<n;j++){
            fr[j] = to[j] = 0;
            g[j].clear();
        }

        for(int it : chosn){
            int &a = ed[it].u;
            int &b = ed[it].v;
            // cerr << a << ' ' << b << '\n';
            g[a].push_back(b);
            g[b].push_back(a);
        }

        T = 0;

        gr[v] = -1;
        dfs(u,-1,u);
        if(gr[u] == gr[v]){//Remove edge with smallest index so the graph stay connected
            int fnd = -1;
            // cerr << i << ' ' << u << ' ' << v << '\n';
            for(int it : chosn){
                int a = ed[it].u;   
                int b = ed[it].v;

                int cnt1 = (fr[v] >= fr[a] && fr[v] <= to[a]);
                int cnt2 = (fr[v] >= fr[b] && fr[v] <= to[b]);
                // cerr << it << ' ' << a << ' ' << b << ' ' << cnt1 << ' ' << cnt2 << '\n';
                if(cnt1 == 1 && cnt2 == 1){
                    fnd = it;
                    break;
                }
            }
	        // cerr << i << ' ' << fnd << '\n';
            assert(fnd != -1);
            chosn.erase(fnd);

        }
        chosn.insert(i);

        if(chosn.size() == n-1){
            int l = *chosn.begin();
            res = min(res , ed[i].w - ed[l].w);
        }
        

    }
    cout << res << '\n';
}

int main(){
    fast
    while(1){
        cin>>n;
        if(!n)break;
        solve();
    }
}

/*
    1- Look at base case (n=1,m=1)
    2- Overflow 
    3- Use assert
*/