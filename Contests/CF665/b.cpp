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
		ll a,b,c,x,y,z;
		cin>>a>>b>>c;
		cin>>x>>y>>z;
		ll v;
		v = min(a,z);
		a -= v;
		z -= v;
		v = min(c,y);
		c -= v;
		y -= v;
		ll ans = v * 2;
		v = min(c,z);
		c -= v;
		z -= v;
		v = min(b,z);
		ans -= v*2;
		cout << ans << '\n';

	}
}