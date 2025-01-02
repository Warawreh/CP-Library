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
		ll x;
		cin>>x;
		bool can = false;
		for(ll a = 1;a*a*a <= x;a++){
			ll b = cbrt(x - a*a*a);
			// if(a == 5779)cerr << b << '\n';
			if(b*b*b + a*a*a == x && b){
				can = true;
				break;
			}
		}
		cout << (can ? "Yes\n" : "No\n");
	}
}