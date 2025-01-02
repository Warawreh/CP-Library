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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll a = n/2;
		ll ans = a*n*n;

		for(ll i=1;i<=n/2;i++){
			ll b = n-i*2;
			// cerr << b << ' ';
			ans -= b*b;
		}
		// cerr << '\n';
		cout << ans << '\n';
	}
}