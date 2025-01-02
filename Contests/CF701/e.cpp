#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll inf = -1e18;

vector<vector<int>> g,at,best,each;
vector<int> a,par,lvl;
vector<ll> dp,dp2,dp3;

void dfs(int u,int p){
	at[lvl[u]].push_back(u);
	best[lvl[u]][0] = min(best[lvl[u]][0] , a[u]);
	best[lvl[u]][1] = max(best[lvl[u]][1] , a[u]);
	for(int v : g[u]){
		if(v == p)continue;
		each[u][0] = min(each[u][0] , a[v]);
		each[u][1] = max(each[u][1] , a[v]);
		lvl[v] = lvl[u] + 1;
		par[v] = u;
		dfs(v,u);
	}
}

ll calc(int u){
	if(at[lvl[u]+1].size() == 0)return 0;
	ll &ret = dp[u];
	ll &ret2 = dp2[lvl[u]];
	ll &ret3 = dp3[lvl[u]];
	if(ret != inf)return max(ret,max(ret2 - each[u][0], ret3 + each[u][1]));
	ret = 0;
	int mn = 2e9,mx = -1;
	int mn2 = 2e9,mx2 = -1;
	mn2 = best[lvl[u] + 1][0];
	mx2 = best[lvl[u] + 1][1];
	for(int v : g[u]){
		if(v == par[u])continue;
		mn = min(mn,a[v]);
		mx = max(mx,a[v]);
		ret = max(ret , calc(v) + max(abs(a[v] - mn2) , abs(a[v] - mx2)));
		// if(u == 10 && v == 1)cerr << calc(v) << '\n';
	}
	if(ret2 != inf){
		return max(ret,max(ret2 - mn, ret3 + mx));
	}
	// if(ret2 != -1)return max(ret, ret2);
	// ret2 = ret3 = (ll)-1e18 + (ll)1e9 * 2e5 + 2;
	for(int v : at[lvl[u] + 1]){
		ret2 = max(ret2 , calc(v) + a[v]);
		ret3 = max(ret3 , calc(v) - a[v]);
	}
	return max(ret,max(ret2 - mn , mx + ret3));
}

void solve(){
	int n;
	cin>>n;
	g = at = vector<vector<int>>(n + 1);
	best = each = vector<vector<int>>(n + 1,{(int)2e9,-1});
	a = lvl = vector<int>(n + 1);
	dp = dp2 = dp3 = vector<ll>(n + 1,inf);
	par = vector<int>(n + 1);
	for(int i=1;i<n;i++){
		int p;
		cin>>p;
		p--;
		g[i].push_back(p);
		g[p].push_back(i);
	}
	for(int i=1;i<n;i++)cin>>a[i];
	lvl[0] = 0;
	dfs(0,-1);
	cout << calc(0) << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

//2  3 4 5 6 7 8  9 1011121314 15
//11 2 7 6 9 8 10 1 1 1 5 3 15 2