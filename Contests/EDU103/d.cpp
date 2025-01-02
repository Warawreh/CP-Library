#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
string s;
vector<int> dp,dp2;

void solve(){
	cin>>n>>s;
	dp = dp2 = vector<int>(n+2,0);
	dp[n] = 1;
	for(int i=n-1;i>=0;i--){
		if(s[i] == 'R' && (i + 1 < n && s[i+1] == 'L'))dp[i] = 2 + dp[i+2];
		else if(s[i] == 'R')dp[i] = 2;
		else dp[i] = 1;
	}
	// for(int i=0;i<=n;i++)
	// 	cerr << dp[i] << ' ';
	// cerr << '\n';
	dp2[0]++;
	for(int i=0;i<n;i++){
		if(s[i] == 'L' && (i && s[i-1] == 'R')){
			dp2[i+1] += 2 + dp2[i-1];
			// cerr << dp2[i+1] << '\n';
		}
		else if(s[i] == 'L')dp2[i+1] += 2;
		else dp2[i+1]++;
	}
	// for(int i=0;i<=n;i++)
	// 	cerr << dp2[i] << ' ';
	// cerr << '\n';
	for(int i=0;i<=n;i++)
		cout << dp[i] + dp2[i] - 1 << ' ';
	cout << '\n';

}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}