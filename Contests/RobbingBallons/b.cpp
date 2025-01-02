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
	ll n,x,y;
	cin>>n>>x>>y;
	ll ans = 1;
	ll lo=1,hi=1e18;
	while(lo <= hi){
		ll md = (lo + hi)/2;
		ll cnt = (ll)md/x + (ll)md/y;
		if(cnt >= n){
			hi = md-1;
			ans = md;
		}else lo = md + 1;
	} 
	cout << ans << '\n';
}