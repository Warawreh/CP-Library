#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
vector<pair<int,int>> dp;
vector<int> depth,par;

void dfs(int u,int p){
	dp[u] = {depth[u] , 0};
	for(int v : g[u]){
		if(v == p)continue;
		depth[v] = depth[u] + 1;
		par[v] = u;
		dfs(v,u);
		if(dp[v].first > dp[u].first){
			dp[u].second = dp[u].first;
			dp[u].first = dp[v].first;
		}else if(dp[v].first > dp[u].second)dp[u].second = dp[v].first;
	}
}

bool can;
int n,a,b,w;
deque<int> q;

void go(int u){
	if(u != a){
		// cerr << u << ' ' << best << '\n';
		int x = q.front();
		q.pop_front();
		int y = q.front();
		int best = dp[x].first;
		if(best == dp[y].first)best = dp[x].second;
		if(best - depth[x] >= depth[a] && depth[a] - depth[x] >= w)can = 1;
		q.push_front(x);
	}
	for(int v : g[u]){
		if(v == par[u])continue;
		int tmp = q.front();
		q.pop_front();
		q.push_back(v);
		go(v);
		q.pop_back();
		q.push_front(tmp);
	}
}

int nono;
void go2(int u){
	if(dp[u].second - depth[u] >= depth[a] && u != b){
		can = 1;
	}
	for(int v : g[u]){
		if(v == par[u] || v == nono)continue;
		go2(v);
	}
}

void solve(){

	cin>>n>>a>>b;

	{
		can = false;
		g.clear();par.clear();dp.clear();depth.clear();
		g.resize(n+1);
		par.resize(n+1);
		dp.resize(n+1);
		depth.resize(n+1);
		while(q.size())q.pop_back();
	}

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(b,0);
	int u = a;
	while(u){
		q.push_front(u);
		u = par[u];
	}
	w = 0;
	int x = q.front();
	q.pop_front();
	int y = q.front();
	nono = y;
	w = dp[x].first;
	if(w == dp[y].first)w = dp[x].second;
	q.push_front(x);
	// cerr << x << ' ' << y << ' ' << dp[b].first << ' ' << dp[b].second << '\n';
	go(a);
	go2(b);
	cout << (can ? "YES\n" : "NO\n");
}

int main(){
	fast
	freopen("C:\\Users\\Magic Systems\\Desktop\\New folder\\C++\\Simpleline3\\input.txt","r",stdin);
	freopen("C:\\Users\\Magic Systems\\Desktop\\New folder\\C++\\Simpleline3\\output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}