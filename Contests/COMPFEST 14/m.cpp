#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n,m;
	cin>>n>>m;

	vector<vector<pair<int,ll>>> g(n),r(n);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		g[u].push_back({v,w});
		r[v].push_back({u,w});
	}

	priority_queue<pair<ll,int>> q1,q2;
	vector<ll> dist1(n,1e18) , dist2(n,1e18);
	{
		q1.push({0,0});
		dist1[0] = 0;
		while(q1.size()){
			int u = q1.top().second;
			ll cst = -q1.top().first;
			q1.pop();

			if(dist1[u] < cst)continue;
			dist2[u] = dist1[u];
			q2.push({-dist2[u] , u});

			for(auto &[v,w] : g[u]){
				ll ncst = cst + w;
				if(ncst >= dist1[v])continue;
				dist1[v] = ncst;
				q1.push({-ncst , v});
			}
		}
	}

	{
		while(q2.size()){
			int u = q2.top().second;
			ll cst = -q2.top().first;
			q2.pop();

			if(dist2[u] < cst)continue;

			for(auto &[v,w] : r[u]){
				ll ncst = cst + w;
				if(ncst >= dist2[v])continue;
				dist2[v] = ncst;
				q2.push({-ncst , v});
			}
		}
	}

	for(int i=1;i<n;i++){
		if(dist2[i] == 1e18)dist2[i] = -1;
		cout << dist2[i] << ' ';
	}
	cout << '\n';
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/