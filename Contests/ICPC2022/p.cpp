#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

vector<vector<int>> g;
int n,m;
string s;
bool cant;

int gv(char c){
    if(c == 'R')return 0;
    else if(c == 'G')return 2;
    else if(c == 'B')return 1;
    return -1;
}

vector<int> val;
vector<bool> seen, vis;
vector<int> curNodes;

void dfs(int u){
    if(cant)return;
    if(vis[u])return;
    vis[u] = 1;
    curNodes.push_back(u);

    if(u < m){
        seen[u] = 1;
        for(int v : g[u]){
            dfs(v);
        }

    }else{

        int curVal = 0;
        int canChange = -1;
        for(int v:g[u]){
            if(val[v] == -1){
                canChange = v;
                continue;
            }
            curVal += val[v];
        }
        int need = (gv(s[u - m]) - curVal + 6)%3;

        if(canChange == -1){
            if(need != 0){
                cant = 1;
                return;
            }
        }else{
            val[canChange] = need;
        }

        for(int v : g[u]){
            dfs(v);
        }

    }

}

int main(){
    fast
    cin>>n>>m;
    g.resize(n + m + 2);
    seen.resize(m);
    val = vector<int>(m, -1);

    cin>>s;

    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        int u = i;
        for(int j=0;j<k;j++){
            int v;
            cin>>v;
            v--;
            v += m;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    ll ans = 0;
    vis = vector<bool>(n + m + 2, 0);
    for(int i=0;i<m;i++){
        if(seen[i])continue;
        int cost = 1e9;
        for(int v=0;v<=2;v++){
            curNodes.clear();
            cant = 0;
            val[i] = v;
            dfs(i);

            int cur = 0;
            for(int u : curNodes){
                if(u < m){
                    cur += val[u];
                    val[u] = -1;
                }
                vis[u] = 0;
            }

            if(cant == 0){
                cost = min(cost, cur);
            }
        }
        if(cost >= 1e9){
            cout << "impossible\n";
            return 0;
        }
        ans += cost;
        // cerr << i << ' ' << cost << '\n';
    }

    for(int i=0;i<n;i++){
        if(s[i] != 'R' && g[i+m].size() == 0){
            cout << "impossible\n";
            return 0;
        }
    }

    cout << ans << '\n';
}
