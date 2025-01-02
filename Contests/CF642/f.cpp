#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<ll>> dp(n,vector<ll>(m,1e18)),g(n,vector<ll>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	dp[n-1][m-1] = 0;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			ll cost = 0;
			if(i + 1 < n){
				if(g[i][j] >= g[i+1][j])cost = g[i][j] - g[i+1][j] + 1;
				else{
					ll len = n-i-1 + m-j-1;
					cost = len * (g[i+1][j] - g[i][j] - 1);
				}
				dp[i][j] = min(dp[i][j] , dp[i+1][j] + cost);
			}
			if(j + 1 < m){
				if(g[i][j] >= g[i][j+1])cost = g[i][j] - g[i][j+1] + 1;
				else{
					ll len = n-i-1 + m-j-1;
					// if(i == 2 && j == 2)cerr << len << '\n';
					cost = len * (g[i][j+1] - g[i][j] - 1);
				}
				dp[i][j] = min(dp[i][j] , dp[i][j+1] + cost);
			}
			cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';	
		}
	}
	cout << dp[0][0] << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();	
}