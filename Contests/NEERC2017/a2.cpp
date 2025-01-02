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
	ll n,k;
	cin>>n>>k;
	ll ans = 1e18;
	if(n <= 2 || n <= k){
		// cout << 1 << '\n';
		return 0;
	}
	ll kk = k;
	for(int use=1;use<k;use++){
		k = kk;
		k -= use;
		ll watch = use;
		watch += min(watch , (ll)(n - watch)/2);
		ll day = 1;
		while(1){
			day++;
			if(n - watch <= k)break;
			watch += min(watch , (ll)(n - watch)/2);
			// cerr << day << ' ' << watch << ' ' << k << '\n';
		}
		
		// cerr << day << '\n';
		ans = min(day , ans);
	}
	cout << ans << '\n';
}