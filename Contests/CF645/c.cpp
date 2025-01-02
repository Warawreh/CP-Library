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
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x2 -= x1;
		y2 -= y1;
		ll x = x2+y2 - 1;
		ll ans = x * (x - 1)/2;
		if(x % 2)ans += x;
		cout << ans << '\n';
	}
}