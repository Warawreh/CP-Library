#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

vector<ll> prime;
vector<int> is_composite;

void sieve (ll n) {
	is_composite = vector<int>(n+1);
	for(ll i=2;i<=n;i++){
		if(is_composite[i])continue;
		ll ad = 1;
		ll to = i*i;
		for(ll j = i;j<=n;j+=i){
			if(to == j){
				to *= i;
				ad++;
			}
			is_composite[j]+=ad;
			if(j == 6){
				cerr << i << ' ' << to << ' ' << ad << '\n';
			}
		}
	}
}

int main(){
	fast
	#ifndef LOCAL
		freopen("valid.in","r",stdin);
	#endif
	int K = 1e8;
	sieve(10 + 1e7);
	// cout << prime.size() << '\n';
	// return 0;
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<vector<ll>> dp(n + 1,vector<ll>(2));
		if(k == 1)dp[0][1] = 1;
		dp[0][0] = 1;

		vector<ll> sum(sqrt(k) + 100);
		for(ll a=2;a<sum.size();a++){
			sum[a] = k / a;
			for(ll i=2;i<a;i++){
				if(i*1LL*a > k)break;
				ll val = k/(i*a);
				cerr << i*a << ' ' << is_composite[i*a] << '\n';
				if(is_composite[i*a] % 2 == 0)sum[a] += val;
				else sum[a] -= val;
			}
			sum[a] %= mod; 
			sum[a] += mod;
			sum[a] %= mod;
			// cerr << a << ' ' << sum[a] - sum[a-1] << '\n';
		}
		ll good = -1;
		for(ll i : prime){
			if(k % i == 0){
				good = i;
				break;
			}
		}
		// break;
		for(ll i=1;i<=n;i++){
			ll a;
			cin>>a;
			if(a == 1){
				dp[i][0] = dp[i-1][0];
				dp[i][1] = dp[i-1][1];	
			}else if(a == k){
				dp[i][1] = (dp[i-1][0] + dp[i-1][1])%mod;
			}else if(a * a > k){
				dp[i][0] = dp[i-1][0];
				dp[i][1] = dp[i-1][1];
			}else if(a*a == k){
				dp[i][0] = dp[i-1][0];
				dp[i][1] = (dp[i-1][1] * 2LL + dp[i-1][0])%mod;
			}else{
				ll cnt = sum[a];
				dp[i][1] = (dp[i-1][1] * cnt)%mod;
				if(a == good){
					dp[i][1] = (dp[i][1] + dp[i-1][0])%mod;
					if(cnt)dp[i][0] = (dp[i-1][0] * (cnt - 1))%mod;
				}else{
					dp[i][0] = (dp[i-1][0] * cnt)%mod;
				}
			}
			// cerr << dp[i][0] << ' ' << dp[i][1] << '\n';
		}
		cout << dp[n][1] << '\n';
	}

}