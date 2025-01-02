#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool dp[n][30];
vector<vector<int>> g;
vector<int> f;

void dfs(int u,int p){
	if(g[u].size() == 1 && p != -1)dp[u][0] = dp[u][1] = 1;
	for(int v : g[u]){
		if(v == p)continue;
		dfs(v,u);
		dp[u][2] |= dp[v][0];
		dp[u][3] |= dp[v][1];
		for(int i=0;i<n;i++){

		}
	}
}

int main(){
	fast
	int n;
	cin>>n;
	f = {1,1};
	for(int i=2;;i++){
		int nxt = f[i-1] + f[i-2];
		if(nxt > n)break;
		f.push_back(nxt);
	}
	if(f.back() != n){
		cout << "No\n" << '\n';
		return 0;
	}
	g.resize(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}