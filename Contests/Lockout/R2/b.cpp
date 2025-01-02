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
	ll ans = 0;
	for(int i=2;i<n;i++){
		ll tmp = n;
		while(tmp){
			ans += tmp%i;
			tmp/=i;
		}
	}
	ll g = __gcd(ans,(ll)n-2);
	ans /= g;
	ll v = (n-2)/g;
	cout << ans << '/' <<  v << '\n';
}