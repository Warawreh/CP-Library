#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

////////////Errichto Debug
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//////////////

vector<vector<int>> g;
vector<int> c,sz;

void dfs(int u,int p){
	sz[u] = !c[u];
	for(int v : g[u]){
		if(v == p)continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

void solve(){
	int n;
	cin>>n;
	sz.clear();
	sz.resize(n+1);
	c.clear();
	c.resize(n+1);
	g.clear();
	g.resize(n+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += (sz[i] == 1 && c[i] == 0);
	}
	cout << (ans + 1) / 2 << '\n';
}

int main(){
	fast
	#ifndef LOCAL
		freopen("tree.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}