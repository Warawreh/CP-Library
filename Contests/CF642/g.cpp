#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<ll>> g;
int n,m;

ll calc(ll val){

	vector<vector<ll>> dp(n,vector<ll>(m,1e18));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			// cerr << val << i << ' ' << j << '\n';
			ll cost = g[i][j] - (val + i + j);
			// cerr << i << ' '  << j << ' ' << val << ' ' << cost << ' ' << g[i][j] << '\n';
			if(cost < 0)continue;
			if(!i && !j)dp[i][j] = cost;
			if(i){
				dp[i][j] = min(dp[i][j] , dp[i-1][j] + cost);
			}
			if(j){
				dp[i][j] = min(dp[i][j] , dp[i][j-1] + cost);
			}
		}
	}
	return dp[n-1][m-1];
}

void solve(){
	cin>>n>>m;
	g = vector<vector<ll>>(n,vector<ll>(m,1e18));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	ll ans = 1e18;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans = min(ans , calc(g[i][j] - i - j));
		}
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();	
}