#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<int,int>>> g;
vector<vector<int>> cost;

void dij(int st){
	priority_queue<pair<int,int>> q;
	cost[st][st] = 0;
	q.push({0,st});
	while(q.size()){
		int u = q.top().second;
		int cst = -q.top().first;
		q.pop();
		if(cst > cost[st][u])continue;
		for(pair<int,int> cur : g[u]){
			int v = cur.first;
			int w = cur.second;
			if(w + cst >= cost[st][v])continue;
			cost[st][v] = w + cst;
			q.push({-cost[st][v] , v});
		}
	}
}

int main(){
	fast
	int n,m,k;
	cin>>n>>m>>k;
	g.resize(n);
	cost.resize(n,vector<int>(n,2e9));
	vector<pair<int,int>> e(m);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		e[i] = {u,v};
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<n;i++){
		dij(i);
	}
	vector<pair<int,int>> p(k);
	for(int i=0;i<k;i++){
		cin>>p[i].first>>p[i].second;
		p[i].first--;
		p[i].second--;
	}
	int ans = 2e9;
	for(int i=0;i<m;i++){
		int cur = 0;
		for(int j=0;j<k;j++){
			int u = p[j].first;
			int v = p[j].second;
			int x = e[i].first;
			int y = e[i].second;
			cur += min(cost[u][v] , min(cost[u][x] + cost[y][v] , cost[u][y] + cost[x][v]));
			// cerr << cost[u][v] << ' ' << min(cost[u][x] + cost[y][v] , cost[u][y] + cost[x][v]) << '\n';
		}
		// cerr << '\n';
		// cerr << i << ' ' << cur << '\n';
		ans = min(ans , cur);
	}
	cout << ans << '\n';
}