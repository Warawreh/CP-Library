#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll h,c,t;

ld get(ll times){
	ll cold = times/2;
	ll hot = times - cold;
	ll total = h * hot + cold * c;
	return total / (times + 0.0);
}

int main(){
	fast
	int T;
	cin>>T;	
	while(T--){
		cin>>h>>c>>t;
		if(h+c >= 2*t){
			cout << 2 << '\n';
		}else{
			ll x = 2*t - h - c;
			ll a = (h-t) / x;
			a = max(a , 0ll);
			ll b = a+1;
			ld vala = abs(t - get(2*a+1));
			ld valb = abs(t - get(2*b+1));

			// cerr << vala << ' ' << valb << '\n';
			// cerr << 2*a +1 << ' ' << 2*b+1 << '\n';
			if(vala <= valb)cout << a*2+1 << '\n';
			else cout << 2*b+1 << '\n';
		}
	}
}