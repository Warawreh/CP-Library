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
	int n;
	cin>>n;

	if(n <= 2){
		cout << n << '\n';
		return 0;
	}

	const int mod = 1e9 + 7;
	ll ans = 0;

	vector<int> dp(n+n+2,0);
	
	for(int i=3;i<=n;i++){
		dp[i] = (dp[i] + 1)%mod;

		for(int j=i;j<=n+n;j+=i){	
			if(i != j)dp[j-1] = (dp[i] + dp[j-1])%mod;
			if(i != j)dp[j] = (dp[i] + dp[j])%mod;
			dp[j+1] = (dp[i] + dp[j+1])%mod;
		}
		// cerr << i << ' ' << dp[i]  << '\n';
		if((n+1)%i>2)
			dp[n] = (dp[n] + dp[i])%mod;
		// if(i + 1 <= n)dp[i] = (dp[i] + 1)%mod;

	}

	cout << (dp[n] * 2LL * n)%mod << '\n';

}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/