#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a,b,c,d;
int main(){
	fast
	cin>>a>>b>>c>>d;
	ll ans = 0;
	for(ll x=a;x<=b;x++){
		ll by = d + 1 -x,wy = c+1-x;
		// 	 << x << ' ' << by << ' ' << wy << ' ';

		if(by <= c){
			by = max(by,b);
			ans += (c - by + 1) * (d - c + 1);
		}

		if(wy <= c){
			ll len = c - wy + 1;
			len = min(len , d - c);
			ans += len * (len + 1)/2;
			if(wy <= b){
				len = b - wy;
				// cerr << ' ' << len << '\n';
				len = min(len , d - c);
				ans -= len * (len + 1)/2;
			}
		}
		// cerr << ans << '\n';
	}
	cout << ans << '\n';
}