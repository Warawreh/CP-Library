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
		ll n,k;
		cin>>n>>k;
		ll sum = 0,ans = 0;
		for(int i=0;i<n;i++){
			ll a;
			cin>>a;
			if(i && sum * k < a * 100){
				// cerr << sum << ' ' << a << ' ' << a * 100 - sum * k << '\n';
				ll need = a * 100 - sum * k;
				need = (need + k - 1)/k;
				ans += need;
				sum += need;
			}
			sum += a;
		}
		cout << ans << '\n';
	}
}