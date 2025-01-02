#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2e5 + 10;

vector<int> g[nax];
int a[nax],b[nax],c[nax];
ll ans = 0;

pair<int,int> calc(int u,int p,int cost){
	cost = min(cost , a[u]);

	pair<int,int> res;
	if(b[u] != c[u]){
		if(b[u])res.second++;
		else res.first++;
	}
	for(int v : g[u]){
		if(v == p)continue;
		pair<int,int> tmp = calc(v,u,cost);
		res.first += tmp.first;
		res.second += tmp.second;
	}
	int x = min(res.first , res.second);
	ans += 2 * x * 1ll * cost;
	res.first -= x;res.second -= x;
	return res;
}

int main(){
	fast
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	pair<int,int> y = calc(1,0,a[1]);
	if(y.first || y.second)ans = -1;
	cout << ans << '\n';
}