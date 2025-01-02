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
		vector<ll> a(n),b(n);
		ll x=1e9,y=1e9;
		for(int i=0;i<n;i++){
			cin>>a[i];
			x = min(x , a[i]);
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
			y = min(y , b[i]);
		}
		ll ans = 0;
		for(ll i=0;i<n;i++){
			ll dx = a[i] - x;
			ll dy = b[i] - y;
			ll w = max(dx , dy);
			ans += w;
		}
		cout << ans << '\n';
	}
}