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
int n;

void find(int u,int p){
	sz[u] = 1;
	for(int v : g[u]){
		if(v == p)continue;
		find(v,u);
		sz[u] += sz[v];
		if(sz[v] * 2 == n){
			assert(x.first == -1);
			x = {v,u};
		}
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n;

		g.clear();
		sz.clear();
		g.resize(n+1);sz.resize(n+1);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		x = {-1,-1};
		find(1,0);
		if(x.first == -1){
			cout << "1 2\n";
			cout << "1 2\n";
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