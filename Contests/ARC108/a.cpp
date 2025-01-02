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
	ll s,p;
	cin>>s>>p;
	for(ll n = 1;n*n<=p;n++){
		if(p % n == 0){
			ll m = p/n;
			if(m + n == s){
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
}