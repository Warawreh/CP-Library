#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;
	ll sumX2 = 0,sumX = 0;
	ll sumY2 = 0,sumY = 0;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		sumX2 = (sumX2 + (x * x)%mod)%mod; 
		sumX = (sumX + x)%mod;

		sumY2 = (sumY2 + (y * y)%mod)%mod; 
		sumY = (sumY + y)%mod;
	}

	int q;
	cin>>q;
	ll ans = 0;
	while(q--){
		ll r,c;
		cin>>r>>c;

		ll cur = (sumX2 + sumY2 + ((r*r)%mod * n)%mod + ((c*c)%mod * n)%mod)%mod;
		cur = (cur - (2*r*sumX)%mod + mod)%mod;
		cur = (cur - (2*c*sumY)%mod + mod)%mod;
		ans = (ans + cur)%mod;
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}