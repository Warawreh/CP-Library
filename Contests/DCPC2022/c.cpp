#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prime;
vector<bool> is_composite;
const int nax = 1e6 + 10;
int U[nax];
void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

const ll want = (1LL << 56) - 1;

void solve(){
	int n,l,r;
	cin>>n>>l>>r;
	vector<int> a(n),u(n);
	ll sum = 0;

	for(int i=0;i<n;i++){
		cin>>a[i];
		u[i] = U[a[i]];
		sum += a[i];
	}

	vector<ll> dp(sum + 1,0);
	dp[0] = 1;
	for(int i=0;i<n;i++){
		for(int j=sum - a[i];j>=0;j--){
			ll nxt = dp[j];
			for(int x=0;x<u[i];x++){
				nxt *= 2;
				nxt &= want;
			}
			dp[j+a[i]] |= nxt;
		}
	}

	ll ans = 1e18;
	for(int i=0;i<=sum;i++){
		for(int j=l;j<=r;j++){
			if(dp[i] == -1)continue;
			if((dp[i] >> j) & 1){
				ans = min(ans , abs(i - (sum - i)));
			}
		}
	}
	if(ans == 1e18)ans = -1;
	cout << ans << '\n';

}

int main(){
    fast
    sieve(1e6+10);
    for(int p : prime)
    	for(int i=p;i<nax;i+=p)
    		U[i]++;
    int t;
    cin>>t;
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/