#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

int main(){
	fast
	ll l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;

	// ll ans2 = 0;
	// for(ll i=l;i<=r;i++){
	// 	ans2 += (i * x)%mod;
	// 	ans2 += ((ll)((i-1)/k) * y)%mod;
	// }
	// cout << ans2%mod << '\n';

	ll ans = (r-l+1) * (l+r) / 2;
	ans %= mod;
	ans *= x;
	ans %= mod;
	ll fr = (l + k - 1)/k;
	ll to = (r - 1) / k;
	to--;

	if(fr <= to){
		ll cur = (to - fr + 1) * (to + fr)/2;
		cur %= mod;
		cur *= k;
		cur %= mod;
		cur *= y;
		cur %= mod;
		ans += cur;
		ans %= mod;
	}

	if(l != r){
		ans += (((min(r,(k*fr)) - l + 1) * (fr - 1))%mod)*y;
		ans %= mod;
	}

	
	ans += (((r - max((k*(to+1)+1),l) + 1) * (to+1))%mod)*y;
	ans %= mod;

	cout << ans << '\n';

}