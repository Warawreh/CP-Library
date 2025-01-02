#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,k;
vector<vector<vector<int>>> g;

ll dij(ll x){
	vector<ll> dist(n,1e18);
	priority_queue<pair<ll,int>> q;
	dist[0] = 0;
	q.push({0,0});

	while(q.size()){
		int u = q.top().second;
		ll cst = -q.top().first;
		q.pop();
		if(cst > dist[u])continue;

		for(int i=0;i<g[u].size();i++){
			int v = g[u][i][0];
			ll c = g[u][i][1];
			ll w = g[u][i][2];
			if(w > x)continue;
			ll ncst = c + cst;
			if(ncst >= dist[v])continue;
			dist[v] = ncst;
			q.push({-ncst , v});
		}
	}
	return dist[n-1];
}

void solve(){
	cin>>n>>m>>k;
	g.clear();
	g.resize(n);
	for(int i=0;i<m;i++){
		int u,v,c,w;
		cin>>u>>v>>c>>w;
		u--;v--;
		g[u].push_back({v,c,w});
		g[v].push_back({u,c,w});
	}

	int lo = 1,hi = 1e9,ans = -1;
	while(lo <= hi){
		int md = (lo + hi)/2;

		if(dij(md) < k){
			hi = md-1;
			ans = md;
		}else lo = md + 1;
	}
	cout << ans << '\n';
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