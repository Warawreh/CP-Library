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
	string s;
	int n;
	getline(cin,s);
	n = s.size();
	vector<vector<int>> dp(n+1,vector<int>(2,1e9));
	dp[0][0] = 0;
	for(int i=0;i<n;i++){
		if(islower(s[i]) || s[i] == ' '){
			dp[i + 1][0] = min(dp[i+1][0] , min(dp[i][0] + 1,dp[i][1] + 3));
			dp[i + 1][1] = min(dp[i+1][1] , min(dp[i][0] + 3,dp[i][1] + 2));
		}
		if(isupper(s[i]) || s[i] == ' '){
			dp[i + 1][0] = min(dp[i+1][0] , min(dp[i][0] + 2,dp[i][1] + 3));
			dp[i + 1][1] = min(dp[i+1][1] , min(dp[i][0] + 3,dp[i][1] + 1));
		}
		// cerr << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
	cout << min(dp[n][0] , dp[n][1]) << '\n';
}