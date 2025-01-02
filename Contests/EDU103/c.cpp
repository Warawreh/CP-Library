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
		ll n;
		cin>>n;
		vector<ll> c(n),a(n),b(n);
		for(ll i=0;i<n;i++)cin>>c[i];
		for(ll i=0;i<n;i++)cin>>a[i];
		for(ll i=0;i<n;i++)cin>>b[i];
		ll ans = 0,cur = c[n-1];
		for(ll i=n-1;i>=1;i--){
			// cerr << a[i] << ' ' << b[i] << '\n';
			if(a[i] == b[i]){
				ans = max(ans , cur + 1);
				cur = c[i - 1];
			}else{
				if(a[i] > b[i])swap(a[i] , b[i]);
				ans = max(ans , cur + b[i] - a[i] + 1);
				cur += a[i] + (c[i - 1] - b[i] + 1);
			}
			cur = max(cur , c[i-1]);
			// cerr << cur << '\n';
		}
		cout << ans << '\n';
	}
}