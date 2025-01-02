#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<ll> c,ans,hvC,totC;
vector<vector<pair<int,int>>> g;


typedef ll T;
vector<T> sz;
vector<bool> big;

void calc(int u,int p){
    sz[u] = 1;
    // cerr << u << ' ' << p << '\n';
    for(auto &[v,id] : g[u]){
        if(v == p)continue;
        calc(v,u);
        sz[u] += sz[v];
    }
}

ll sum = 0;

void add(int u,int p,T val){
    
    sum -= totC[c[u]] * hvC[c[u]];

    hvC[c[u]] += val;
    totC[c[u]] -= val;

    sum += totC[c[u]] * hvC[c[u]];

    for(auto &[v,id] : g[u]){
        if(v == p || big[v])continue;
        add(v,u , val);
    }
}

ll dfs(int u,int p,bool keep){
    int mx = -1,bigChild = -1,at = -1;
    for(auto &[v,id] : g[u]){
    	if(v == p)continue;
        if(sz[v] > mx){
        	at = id;
            mx = sz[v];
            bigChild = v;
        }
    }
    for(auto &[v,id] : g[u]){
        if(v == p || v == bigChild)continue;
        ans[id] = dfs(v , u , 0);
    }
    if(bigChild != -1){
        ans[at] = dfs(bigChild , u , 1);
        big[bigChild] = 1;
    }
    add(u , p , 1);
    ll res = sum;
    if(bigChild != -1){
        big[bigChild] = 0;
    }
    if(keep == 0)add(u , p , -1);
    return res;
}

int main(){
    fast
	cin>>n;
	c = sz = totC = hvC = ans = vector<ll>(n);
	big = vector<bool>(n);
	g.resize(n);
	for(int i=0;i<n;i++){
		cin>>c[i];
		c[i]--;
		totC[c[i]]++;
	}
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	for(int i=0;i<n;i++){
		if(g[i].size() == 1){
			calc(i , -1);
			dfs(i , -1 , 0);
			break;
		}
	}

	for(int i=0;i<n-1;i++)
		cout << ans[i] << ' ';
	cout << '\n';
}
