#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

int n,m;
vector<vector<pair<int,int>>> g;

struct node{
	int u,cst,used,t;
	node(int a,int b,int c,int d){
		u = a;
		cst = b;
		used = c;
		t = d;
	}
	bool operator<(const node rhs)const{
		if(cst == rhs.cst)return used < rhs.used;
		return cst < rhs.cst;
	}
};



const int nax = 2e5 + 100;
int p2[2*nax];
int cost[nax][20][2];

void dij(){
	memset(cost , -1,sizeof(cost));
	priority_queue<node> q;
	cost[0][0][0] = 0;
	q.push({0,0,0,0});
	ll ans = 1e18;
	int cnt = 0;
	while(q.size()){
		int u = q.top().u;
		int cst = -q.top().cst;
		int used = -q.top().used;
		int t = q.top().t;
		q.pop();
		// cnt++;
		// cerr << u << ' ' << used << ' ' << t << ' ' << cst << '\n';
		// cerr << u << '\n';
		if(u == n-1){
			ans = min(ans , cst * 1LL);
		}
		if(cst > cost[u][used][t])continue;
		for(pair<int,int> cur : g[u]){
			int v = cur.first;
			int w = cur.second ^ t;
			int ncst = cst + 1 + (w ? p2[used] : 0);
			// cerr << v << ' ' << ncst << '\n';
			if(used + w > 18)continue;
			if(ncst >= cost[v][used + w][t ^ w] && cost[v][used + w][t ^ w] != -1)continue;
			cost[v][used + w][t ^ w] = ncst;
			q.push(node(v,-ncst,-(used + w),t ^ w));
		}
	}
	// cout << cnt << '\n';
	if(ans != 1e18){	
		cout << ans << '\n';
		exit(0);
	}
}

struct node2{
	int u,cst,used,t;
	node2(int a,int b,int c,int d){
		u = a;
		cst = b;
		used = c;
		t = d;
	}
	bool operator<(const node2 rhs)const{
		if(used == rhs.used)return cst < rhs.cst;
		return used < rhs.used;
	}
};

pair<int,int> cost2[nax][2];

void dij2(){
	memset(cost2 , -1,sizeof(cost2));
	priority_queue<node2> q;

	for(int i=0;i<n;i++){
		for(int j=0;j<=18;j++){
			if(cost[i][j][0] != -1 ){
				q.push({i,cost[i][j][0] - (p2[j] - 1),j,0});
				cost2[i][0] = {j,cost[i][j][0] - (p2[j] - 1)};
			}
			if(cost[i][j][1] != -1 ){
				q.push({i,cost[i][j][1] - (p2[j] - 1),j,1});
				cost2[i][1] = {j,cost[i][j][1] - (p2[j] - 1)};
			}
		}
	}

	while(q.size()){
		int u = q.top().u;
		int cst = -q.top().cst;
		int used = -q.top().used;
		int t = q.top().t;
		q.pop();
		if(make_pair(used,cst) > cost2[u][t])continue;
		cost2[u][t] = make_pair(used,cst);
		for(pair<int,int> cur : g[u]){
			int v = cur.first;
			int w = cur.second ^ t;
			pair<int,int> ncst = {used + w , cst + 1};
			if(ncst >= cost2[v][t ^ w] && cost2[v][t^w].first != -1)continue;
			cost2[v][t ^ w] = ncst;
			q.push(node2(v,-(cst + 1),-(used + w),t ^ w));
		}
	}
	if(cost2[n-1][0].first == -1)cost2[n-1][0] = make_pair((int)1e9,(int)1e9);
	if(cost2[n-1][1].first == -1)cost2[n-1][1] = make_pair((int)1e9,(int)1e9);
	pair<int,int> ans = min(cost2[n-1][0] , cost2[n-1][1]);
	// cerr << ans.first << ' ' << ans.second << '\n';
	cout << (p2[ans.first] - 1 + mod + ans.second)%mod << '\n';
}

int main(){
	fast
	cin>>n>>m;
	p2[0] = 1;
	for(int i=1;i<=2*n;i++)p2[i] = (p2[i-1] * 2LL)%mod;
	g.resize(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back({v,0});
		g[v].push_back({u,1});
	}
	dij();
	dij2();
}