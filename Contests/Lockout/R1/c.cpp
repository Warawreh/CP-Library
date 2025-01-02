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
	ll at = 0;
	ll e = 0;
	ll ans = 0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		e += at - a;
		// cerr << e << '\n';
		if(e < 0){
			ans += -e;
			e = 0;
		}
		at = a;
	}
	cout << ans << '\n';
}