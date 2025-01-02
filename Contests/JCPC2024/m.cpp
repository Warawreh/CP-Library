#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int mod = 1e9 + 7;

struct DSU{
    vector<int> par, sz;

    DSU(int n){
        par = sz = vector<int>(n, 1);
        iota(all(par), 0);
    }

    int find(int u){
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    void merge(int u,int v){
        u = find(u);
        v = find(v);
        if(u == v)return;
        if(sz[u] < sz[v])swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
};

void solve(){
    int n;
    cin>>n;

    vector<int> at1(n), at2(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        at1[u] = i;
        at2[v] = i;
    }


    DSU d(n);
    for(int i=0;i<n;i++){
        d.merge(at1[i], at2[i]);
    }

    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(d.find(i));
    }

    ll ans = 1;
    for(int i=0;i<st.size();i++){
        ans = (ans * 2) % mod;
    }

    cout << (ans - 1 + mod)%mod << '\n';
}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}
