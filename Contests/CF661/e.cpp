#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<vector<ll>>> g;
vector<ll> sz;
priority_queue<ll> st[2];
ll ans,cur;

void dfs(int u,int p){
	bool leaf = true;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i][0];
		ll w = g[u][i][1];
		int c = g[u][i][2];
		if(v == p)continue;
		leaf = false;
		cur += w;
		dfs(v,u);
		ll nxt = 0;
		cur -= w;
		while(w){
			nxt = w/2;
			st[c].push(sz[v] * 1LL * (w - nxt));
			w/=2;
		}
		sz[u] += sz[v];
	}
	sz[u] += leaf;
	if(leaf)ans += cur;
}

void solve(){
	ll n,s;
	cin>>n>>s;

	g.clear();
	g.resize(n+1);
	sz.clear();
	sz.resize(n+1);

	while(st[1].size())st[1].pop();
	while(st[0].size())st[0].pop();

	cur = 0;
	ans = 0;

	for(int i=0;i<n-1;i++){
		int u,v,cst;
		ll w ;
		cin>>u>>v>>w>>cst;
		cst--;
		g[u].push_back({v,w,cst});
		g[v].push_back({u,w,cst});
	}
	dfs(1,0);
	ll need = 0;
	vector<ll> pre;
	ll sum = 0;
	while(st[0].size()){
		sum += st[0].top();
		st[0].pop();
		pre.push_back(sum);
	}
	ll res = 1e18;
	if(ans <= s)res = 0;
	if(pre.size() && ans - pre.back() <= s){
		ll ne = ans - s;
		ll g = lower_bound(all(pre) , ne) - pre.begin() + 1;
		res = min(res , g);
	}
	while(st[1].size()){
		ll cur = st[1].top();
		st[1].pop();
		ans -= cur;
		need += 2;
		ll ne = ans - s;
		if(pre.size() && pre.back() >= ne){
			ll g = need + (lower_bound(all(pre) , ne) - pre.begin()) + 1;
			res = min(res , g);
		}
		// cerr << need << ' ' << upper_bound(all(pre) , ne) - pre.begin() << '\n';
		if(ans <= s){
			res = min(res , need);
			break;	
		}

	}
	cout << res << '\n';
	return;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}