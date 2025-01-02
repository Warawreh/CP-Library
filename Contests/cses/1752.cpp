#include <bits/stdc++.h>
using namespace std;
 
stringstream ss;
 
int n, D;
vector<int> p(200001);
vector<int> r(200001);
vector<int> adj[200001];
vector<int> de[200001];
 
void dfs(int now, int prv, int lv) {
	de[lv].push_back(now);
	p[now] = prv;
	for (int u: adj[now]) {
		if (u != prv) dfs(u, now, lv+1);
	}
}
 
int go(int u, int d) {
	if (!u || !d) return 1;
	if (r[u] + d > D) return 0;
	r[u] = d;
	return go(p[u], d - 1);
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> D;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0, 0); 
 
	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int u: de[i]) {
			if (go(u, D)) {
				ans++;
				ss << u << ' ';
			}
		}
	}
	cout << ans << '\n' << ss.str() << '\n';
 
	return 0;
}