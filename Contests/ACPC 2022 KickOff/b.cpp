#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<int,int>>> g;
const int nax = 1e5 + 10;
int dp[51][nax];
const int mod = 1e9 + 7;

int calc(int u,int k){
	if(k < 0)return 0;
	if(k == 0)return 1;
	int &ret = dp[u][k];
	if(ret != -1)return ret;
	ret = 0;
	for(auto &[v,w] : g[u]){
		if(w > k)continue;
		ret = (ret + calc(v, k - w))%mod;
	}
	return ret;
}


void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	g.clear();
	g.resize(n);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		if(w > k)continue;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j] = -1;

	cout << calc(0,k) << '\n';
}

int main(){
	fast
	freopen("cals.in","r",stdin);	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/