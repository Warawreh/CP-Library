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
		int n;
		cin>>n;
		int a = ceil(sqrt(n));
		int ans = (a - 1) + (n + a - 1)/a;
		if(a > 1){
			a--;
			ans = min(ans,(a - 1) + (n + a - 1)/a);
		}
		cout << ans-1 << '\n';
	}
}