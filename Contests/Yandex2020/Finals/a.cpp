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
	ll n;
	ll k;
	cin>>n>>k;
	ll a=0,b=0,c=0;
	set<vector<ll>> st;
	for(int i=0;i<n;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		c+=z;

		st.insert({-y,x});
	}
	ld ans = 0;
	vector<ll> u = {0,1};
	ld rest = 0;
	ld mx = 0;
	bool w = 0;
	for(auto it : st){
		ll a = it[1];
		ll b = -it[0];
		if(u[0] * a - b * u[1] >= k * a * u[1] && w == false){
			ans += b/2.0 * -b / (2.0 * a);
			// cerr << a << ' ' << b << '\n';
			// cerr << u[0] * a - b * u[1] << ' ' << k * a * u[1] << '\n';
			u[1] += 2*a;
			u[0] += -b;
		}else{
			// cerr << k << ' ' << u[0] / (u[1] + 0.0) << '\n';
			w = 1;
			rest = k - u[0] / (u[1] + 0.0);
			rest = min(rest , (ld)b/(-2.0*a));
			// cerr << -b/(2.0*a) << '\n';
			mx = max(mx , rest*rest*a + rest*b);
			// cerr << rest << ' ' << mx << '\n';
		}
	}
	
	cout << setprecision(12) << fixed << ans+c+mx << '\n';
}