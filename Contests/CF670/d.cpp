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
	int n;
	cin>>n;
	vector<ll> a(n),d(n);
	ll ans = 0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		if(i)d[i] = a[i] - a[i-1];
		ans += max(0LL , (i ? a[i] - a[i-1] : 0));
	}
	cout << (ll)ceil((ans + a[0])/2.0) << '\n';
	ll q;
	cin>>q;
	while(q--){
		ll l,r,x;
		cin>>l>>r>>x;
		l--;r--;
		if(l){
			ans -= max(0LL,d[l]);
			d[l] += x;
			ans += max(0LL,d[l]);
		}else a[l] += x;
		if(r + 1 < n){
			ans -= max(0LL,d[r+1]);
			d[r+1] -= x;
			ans += max(0LL,d[r+1]);
		}
		cout << (ll)ceil((ans + a[0])/2.0) << '\n';
	}
}