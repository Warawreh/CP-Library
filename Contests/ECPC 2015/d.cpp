#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<ll,ll>>> g;
vector<ll> tms;

void dfs(int u,ll d){
	if(g[u].empty()){
		// cerr << u << ' ' << d << '\n';
		tms.push_back(d);
	}

	for(int i=0;i<g[u].size();i++){
		int v = g[u][i].second;
		dfs(v , d + g[u][i].first + (g[u][i].first - g[u][0].first));
	}
}

void solve(){
	int n;
	cin>>n;

	tms.clear();
	g.clear();
	g.resize(n);

	for(int u=1;u<n;u++){
		int v,c;
		cin>>v>>c;
		v--;
		g[v].push_back({c,u});
	}

	for(int i=0;i<n;i++)sort(all(g[i]));

	dfs(0,0);
	sort(all(tms));
	int q;
	cin>>q;
	while(q--){
		ll t;
		cin>>t;
		cout << upper_bound(all(tms) , t) - tms.begin() << '\n';
	}
}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/