#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	ll n,t,r0;
	cin>>n>>t>>r0;
	vector<ll> dp(n+1,1e18);
	dp[0] = r0 * t;
	vector<pair<int,int>> s(n+1);
	s[0] = {0,r0};
	ll ans = 1e18;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
		ll tot = 0;
		tot += s[i].first;
		ll val = 1e18;
		for(int j=i-1;j>=0;j--){
			if(tot > t)break;
			dp[i] = min(dp[i] , dp[j] + s[i].second * tot + 500);
			val = min(val , dp[j]);
			tot += s[j].first;
		}
		if(i == n)ans = val;
	}
	cout << ans << '\n';
}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/