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
		int n,s,k;
		cin>>n>>s>>k;
		int g = gcd(n , k);
		k %= n;
		if(k == 0)k += n;
		if(s % g){
			cout << -1 << '\n';
		}else{
			ll dif = (((s%k)+k)%k) / g;
			cerr << s << ' ' << (s + k)%n << '\n';
			cerr << dif << ' ' << g << ' ' << n%k << '\n';
			cerr << s%k << ' ' << n%k << '\n';
			if(s%k <= n%k){
				cout << (n - s - 1) / k + (n/k) * ((dif - 1 + k)%k) + 1 << '\n';
				cerr << (n - s - 1)/k << ' ' << (n/k) << ' ' << ((dif - 1 + k)%k) << ' ' << g << '\n';
			}else{
				ll v = (s%k) - (n%k);
				v--;
				ll l = (((s%k) - 1 + k)%k);
				cout << (n - s) / k + (n/k) * l - v * (n/k) + 1 << '\n';
				cerr << l << ' ' << g << '\n';
			}
			
			// cerr << (s%k) << ' ' << (n - s) / k << ' ' << (n/k) << ' ' << (((s%k) - 1 + k)%k) << '\n';
		}

	}
}