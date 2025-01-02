#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m,u,l,k;
	cin>>n>>m>>u>>l>>k;
	vector<vector<pair<int,int>>> g(n);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	vector<int> dist(n,-1);
	dist[u - 1] = 0;
	vector<int> q = {u - 1};
	int qh = 0;

	for(qh = 0;qh<q.size();qh++){
		int u = q[qh];

		for(auto &[v,w] : g[u]){
			if(dist[v] != -1)continue;
			dist[v] = dist[u] + 1;
			q.push_back(v);
		}
	}

	int ans = 0;
	for(int u=0;u<n;u++){
		if(dist[u] >= k)continue;
		for(auto &[v,w] : g[u]){
			ans = max(ans , w);
		}
	}
	cout << ans << '\n';
}

int main(){
	fast
	freopen("path.in","r",stdin);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/