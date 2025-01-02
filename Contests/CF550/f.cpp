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
	vector<vector<pair<int,int>>> g(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back({v,i});
		g[v].push_back({u,-(i+1)});
	}
	vector<int> c(n,-1);
	vector<bool> vis(n,false);
	vis[0] = true;
	c[0] = 1;
	queue<int> q;
	q.push(0);
	while(q.size()){
		int u = q.front();
		q.pop();
		int o=0,z=0;
		for(pair<int,int> cur : g[u]){
			int v = cur.first;
			if(c[v] == 1)o++;
			if(c[v] == 0)z++;
		}
		if(o && z){
			cout << "NO\n";
			return 0;
		}
		if(o == 0)c[u] = 1;
		else if(z == 0)c[u] = 0;
		for(pair<int,int> cur : g[u]){
			int v = cur.first;
			if(vis[v] == true)continue;
			vis[v] = true;
			q.push(v);
		}
	}
	string ans(m,'0');
	for(int u=0;u<n;u++){
		for(pair<int,int> cur : g[u]){
			int v = cur.first;
			int id = cur.second;
			if(id < 0){
				id = -id;
				id--;
				ans[id] = char('0' + c[v]);
			}else{
				ans[id] = char('0' + c[u]);
			}
		}
	}
	cout << "YES\n";
	cout << ans << '\n';
}