#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int r,n;
	cin>>r>>n;
	vector<vector<int>> c(n+1);
	c[0] = {0,0,0};
	vector<int> dp(n+1,-1e9);
	int best = -1e9;
	int l = 0;
	int ans = 0;
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		int t,x,y;
		cin>>t>>x>>y;
		x--;y--;
		while(l < i && t - c[l][0] >= 2*r){
			best = max(best , dp[l]);
			l++;
		}
		int cur = best;
		c[i] = {t,x,y};
		for(int j=i-1;j>=l;j--){
			if(abs(c[i][1] - c[j][1]) + abs(c[i][2] - c[j][2]) <= c[i][0] - c[j][0]){
				cur = max(cur , dp[j]);
			}
		}
		dp[i] = cur + 1;
		ans = max(ans , dp[i]);
	}
	cout << ans << '\n';
}