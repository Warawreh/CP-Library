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
	for(ll x=1;x<=1000;x++){
		for(ll y=1;y<=1000;y++){
			ll val = (x * 299) + (y*355);
			if(val % 251 == 0){
				ll z = -val / 251;
				// cerr << (x * 299) << ' ' << (y * 355) << ' ' << (z *251) << '\n';
				cerr << (x * 299) + (y * 355) + (z * 251) << '\n';
				cout << x << ' ' << y << ' ' << z << '\n';
				return 0;
			}
		}
	}
}