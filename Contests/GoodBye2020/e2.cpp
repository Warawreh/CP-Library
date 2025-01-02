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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		ll ans = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					ans += ((a[i] & a[j]) * (a[j]))%mod;
					// cerr << i << ' ' << j << ' ' << k << ' ' << ((a[i] & a[j]) * (a[j]))%mod << '\n';
					ans %= mod;
				}
			}
		}
		cout << ans << '\n';
	}
}