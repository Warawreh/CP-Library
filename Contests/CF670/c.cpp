#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
vector<int> sz;
pair<int,int> x;
int mn;
int n;

void find(int u,int p){
	sz[u] = 1;
	int mx = 0;
	for(int v : g[u]){
		if(v == p)continue;
		find(v,u);
		sz[u] += sz[v];
		mx = max(mx , sz[v]);
	}
	mx = max(mx , n - sz[u]);
	// cerr << u << ' ' << mx << '\n';
	if(mx < mn){
		mn = mx;
		x = {-1,-1};
		x.first = u;
	}else if(mx == mn)x.second = u;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n;

		g.clear();
		sz.clear();
		mn = 1e9;
		g.resize(n+1);sz.resize(n+1);
		x = {-1,-1};
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		find(1,0);
		if(x.second == -1){
			cout << 1 << ' ' << g[1][0] << '\n';
			cout << 1 << ' ' << g[1][0] << '\n';
		}else{
			for(int v : g[x.second]){
				if(v != x.first){
					cout << v << ' ' << x.second << '\n';
					cout << x.first << ' ' << v << '\n';
					break;
				}
			}
		}
	}	
}