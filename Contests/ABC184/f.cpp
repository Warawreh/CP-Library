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
	int n,t;
	cin>>n>>t;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)cin>>a[i];
	ll x = n/2;
	vector<ll> w;
	for(ll i=0;i<(1<<x);i++){
		ll sum = 0;
		for(ll j=0;j<x;j++)if((i>>j) & 1)sum += a[j];
		w.push_back(sum);
	}
	sort(all(w));
	int y = n-x;
	ll ans = 0;
	for(ll i=0;i<(1<<y);i++){
		ll sum = 0;
		for(ll j=0;j<y;j++)if((i>>j) & 1)sum += a[x+j];
		ll at = upper_bound(all(w),t - sum) - w.begin();
		if(at)ans = max(ans , sum + w[at-1]);
	}
	cout << ans << '\n';
}