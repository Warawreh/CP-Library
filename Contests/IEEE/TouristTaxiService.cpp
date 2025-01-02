#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<vector<ll>>> g;
vector<bool> used;
vector<ll> dist5;

void dfs(int u,ll d,int moved){
	// cerr << u << ' ' << d << ' ' << moved << '\n';
	if(moved == 5){
		dist5[u] = min(dist5[u] , d);
		return;
	}
	for(vector<ll> &c : g[u]){
		int v = c[0];
		int w = c[1];
		int i = c[2];
		// if(u == 4 && v == 1)cerr << d << ' ' << moved << ' ' << i << ' ' << used[i] << '\n';
		if(used[i])continue;
		used[i] = 1;
		// cerr << "In " << i << '\n';
		dfs(v , d + w , moved + 1);
		used[i] = 0;
		// cerr << "Out " << i << ' '<<used[i] << '\n';
	}
}

int main(){
    fast
    int n,m;
    cin>>n>>m;
    g.resize(n);
    used.resize(m);
    for(int i=0;i<m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	u--;v--;
    	g[u].push_back({v,w,i});
    	g[v].push_back({u,w,i});
    }
    dist5.resize(n,1e18);
    dfs(0,0,0);
    vector<ll> ans(n , 1e18);
    for(int i=0;i<n;i++){
    	if(dist5[i] == 1e18)continue;

    	priority_queue<pair<ll,int>> q;
    	q.push({-dist5[i] , i});
    	ans[i] = min(ans[i] , dist5[i]);
    	// cerr << i << ' ' << dist5[i] << '\n';
    	while(q.size()){
    		int u = q.top().second;
    		ll cst = -q.top().first;
    		q.pop();

    		if(ans[u] < cst)continue;
    		for(vector<ll> &c : g[u]){
				int v = c[0];
				int w = c[1];
				ll ncst = cst + w;
				if(ncst >= ans[v])continue;
				ans[v] = ncst;
				q.push({-ncst , v});
			}
    	}

    }

    for(int i=0;i<n;i++)
    	cout << ans[i] << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/