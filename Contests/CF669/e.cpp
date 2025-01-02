#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<int,int>>> g;
vector<int> dp,b,w;
vector<bool> vis;
string c;

int main(){
	fast
	int n,m;
	cin>>n>>m;
	
	c = string(n,'0');
	g.resize(n+1);
	b.resize(n+1,1e9);w.resize(n+1,1e9);
	vis.resize(n+1,false);
	dp.resize(n+1,1e9);

	for(int i=0;i<m;i++){
		int u,v,t;
		cin>>u>>v>>t;
		g[v].push_back({u,t});
	}
	queue<int> q;
	vis[n] = 1;
	dp[n] = b[n] = w[n] = 0;
	q.push(n);
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto &[v,t] : g[u]){
			if(t == 0){
				b[v] = min(b[v] , dp[u] + 1);
			}else{
				w[v] = min(w[v] , dp[u] + 1);
			}
			if(w[v] > b[v])c[v-1] = '1';
			dp[v] = max(b[v] , w[v]);

			if(dp[v] < 1e9 && !vis[v]){
				vis[v] = 1;
				q.push(v);
			}
		}
	}

	if(dp[1] >= 1e9)dp[1] = -1;
	cout << dp[1] << '\n';
	cout << c << '\n';
}