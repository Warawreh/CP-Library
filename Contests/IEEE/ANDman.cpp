#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}


typedef ll T;
int n;
vector<T> seg,a;

void initSeg(){
    seg = vector<T>(4*n,1);
}

T merge(T l, T r){
    return (l * r)%mod;
}

void update(int l,int r,T val,int n,int s,int e){
    if(s > r || e < l || l > r)return;
    if(s >= l && e <= r){
        seg[n] = (seg[n] * val)%mod;
        return;
    }

    update(l,r,val,n+n,s,(s+e)/2);
    update(l,r,val,n+n+1,(s+e)/2+1,e);

    seg[n] = merge(seg[n+n] , seg[n+n+1]);
}

T get(int l,int r,int n,int s,int e){
    if(s > r || e < l || l > r)return 1;
    if(s >= l && e <= r)return seg[n];
    
    return merge(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
}

void update(int l,int r,T val){
    update(l,r,val,1,1,n);
}

void update(int at,T val){
    update(at,at,val,1,1,n);
}

T get(int l,int r){
    return get(l,r,1,1,n);
}


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

     
    ll findPath(int u,int P){
        if(u == P)return a[u];
        ll res = 1;
        while(u != -1 && nxt[u] != nxt[P]) {
            if(nxt[u] == u)res = (res * a[u])%mod;
            else res = (res * get(fr[nxt[u]], fr[u]))%mod;

            u = par[nxt[u]];
        }
        res = (res * get(fr[P], fr[u]))%mod;
        return res;
    }
     
    int Find(int u,int v){
        int l = lca(u,v);
        return ((findPath(u,l) * findPath(v , l))%mod * POW(a[l] , mod-2))%mod;
    }
     
     
    void prep(){
        dfs_sz(0,-1);
        dfs_hld(0,-1);
    }
     
};

void solve(){
	scanf("%d",&n);

	initSeg();
	a = vector<ll>(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	HLD hld;
	hld.initHLD(n);
	vector<vector<int>> g(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	hld.setG(g);
	hld.prep();

	for(int i=0;i<n;i++){
		update(hld.fr[i] , a[i]);
	}

	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){//update
			int u,x;
			scanf("%d%d",&u,&x);
			u--;
			update(hld.fr[u] , POW(a[u] , mod-2));
			a[u] = x;
			update(hld.fr[u] , a[u]);
		}else{
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			printf("%d\n",hld.Find(u,v));
			// cout << hld.Find(u,v) << '\n';
		}
	}

}

int main(){
    // fast
    int t;
    scanf("%d",&t);
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/