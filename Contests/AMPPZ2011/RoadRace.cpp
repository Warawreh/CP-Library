#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g,Q;
vector<vector<pair<int,int>>> query;
int n,m,k;

void solve(int fr,int to){
    vector<int> in(n);
    for(int u=0;u<n;u++){
        for(int v : g[u]){
            in[v]++;
        }
    }

    vector<int> q;
    int qh = 0;
    vector<ll> reach(n);
    q.push_back(0);
    for(qh=0;qh<q.size();qh++){
        int u = q[qh];
        if(u >= fr && u <= to){
            reach[u] |= (1LL << (u - fr));
        }
        // cerr << u << ' ' << reach[u] << '\n';
        for(int v : g[u]){
            in[v]--;
            reach[v] |= reach[u];
            if(in[v] == 0){
                q.push_back(v);
            }
        }
    }

    for(int u=fr;u<=to;u++){
        for(pair<int,int> cur : query[u]){
            int v = cur.first;
            int i = cur.second;
            bool can = (reach[v] >> (u - fr)) & 1;
            Q[i][2] |= can;
        }
    }
}

int main(){
    fast
    
    cin>>n>>m>>k;
    g.resize(n);
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
        swap(p[i].first , p[i].second);
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        if(p[u].first == p[v].first){
            if(p[u].second > p[v].second)swap(u,v);
        }else{
            if(p[u].first < p[v].first)swap(u,v);
        }
        g[u].push_back(v);
    }
    Q = vector<vector<int>>(k,vector<int>(3));
    query.resize(n);
    for(int i=0;i<k;i++){
        cin>>Q[i][0]>>Q[i][1];
        Q[i][0]--;
        Q[i][1]--;
        query[Q[i][0]].push_back({Q[i][1] , i});
        query[Q[i][1]].push_back({Q[i][0] , i});
    }
    for(int i=0;i<(n+63)/64;i++){
        int fr = i * 64,to = min(n,(i+1)*64) - 1;
        solve(fr,to);
    }
    for(int i=0;i<k;i++){
        cout << (Q[i][2] ? "TAK\n" : "NIE\n");
    }
}

/*
    1- Look at base case (n=1,m=1)
    2- Overflow 
    3- Use assert
*/