#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
vector<ll> f;

pair<ll,ll> dfs(int u){
	pair<ll,ll> cur = {0,1e18};
	for(int v : g[u]){
		pair<ll,ll> c = dfs(v);
		cur.first += c.first;
		// cerr << u << ' ' << v << ' ' << c. << '\n';
		cur.second = min(cur.second , c.second);
	}

	if(cur.second == 1e18){
		cur.second = 0;
	}
	if(f[u] > cur.second){
		cur.first += f[u] - cur.second;
		cur.second = f[u];
	}
	// cerr << u << ' ' << cur.first << ' ' <<  cur.second << '\n';
	return cur;

}

void solve(){
	int n;
	cin>>n;

	g.clear();
	g.resize(n+1);
	f = vector<ll>(n+1);

	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		g[p].push_back(i);
	}
	
	cout << dfs(0).first << '\n';

}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}