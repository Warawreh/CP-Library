#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
int w[2];

void dfs(int u,int p,int d){
	w[d%2]++;
	for(int v : g[u]){
		if(v == p)continue;
		dfs(v,u,d+1);
	}
}

int main(){
	fast
	int n;
	cin>>n;
	g.resize(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0);
	cout << min(w[0] , w[1]) - 1 << '\n';
}