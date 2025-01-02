#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g,dp;
vector<int> d;

int go(int u,int t){
	if(u == 0)return 0;
	// cerr << '!' << u << ' ' << dp[u][t] << '\n';
	if(dp[u][t] != -1)return dp[u][t];
	dp[u][t] = d[u];
	int best = d[u];
	// cerr << u << ":\n";
	for(int v : g[u]){
		// cerr << v << ' ' << best << ' ' << t << '\n';
		if(d[u] < d[v])best = min(best , go(v,t));
		else if(t == 0)best = min(best , go(v,1));
	}
	return dp[u][t] = best;
}

void solve(){
	int n,m;
	cin>>n>>m;

	d = vector<int>(n,-1);
	g.clear();
	g.resize(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
	}
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int v : g[u]){
			if(d[v] != -1)continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	dp = vector<vector<int>>(n,vector<int>(2,-1));
	for(int i=0;i<n;i++){
		cout << go(i,0) << ' ';
	}
	cout << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}