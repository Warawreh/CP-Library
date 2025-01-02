#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,s;
vector<vector<int>> g;
vector<int> vis;
vector<int> path;
vector<vector<int>> ans;
vector<int> bad;

void dfs2(int u,int p){
	if(u == s)return;
	if(u == p){
		ans.push_back(path);

		cout << "Possible\n";
		for(int i=0;i<2;i++){
			cout << ans[i].size() + 2 << '\n';
			cout << s+1;
			for(int j : ans[i])
				cout << ' ' << j+1;
			cout << ' ' << u+1 << '\n';
		}
		exit(0);
	}
	if(bad[u])return;
	vis[u] = n+1;
	path.push_back(u);

	for(int v : g[u]){
		if(vis[v] == n+1)continue;
		dfs2(v,p);
	}

	path.pop_back();
}

void dfs(int u,int p){
	if(u == s)return;
	if(vis[u] != -1){
		ans.push_back(path);
		bad.resize(n);
		for(int v : path)bad[v] = 1;
		path.clear();
		dfs2(vis[u],u);
		return;
	}
	vis[u] = p;

	path.push_back(u);

	for(int v : g[u]){
		if(vis[v] == p)continue;
		dfs(v,p);
	}

	path.pop_back();
}

int main(){
	fast
	cin>>n>>m>>s;
	s--;
	g.resize(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
	}
	vis = vector<int>(n,-1);

	for(int v : g[s]){
		dfs(v,v);
	}
	cout << "Impossible\n";
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/