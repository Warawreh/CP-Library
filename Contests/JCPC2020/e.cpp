#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int nax = 1e6 + 10;

int main(){
	fast
	#ifndef LOCAL
		freopen("luka.in","r",stdin);
	#endif
	int t;
	cin>>t;

	vector<ll> p11(nax),p2(nax);
	p11[0] = 1;
	p2[0] = 1;
	for(int i=1;i<nax;i++){
		p11[i] = (p11[i-1] * 11LL)%mod;
		p2[i] = (p2[i-1] * 2LL)%mod;
	}

	while(t--){
		int n;
		string s;
		cin>>n>>s;
		ll ans = 0;
		for(int i=0;i<n;i++){
			ll d = s[i] - '0';
			ans += (d * p11[n-i-1] * p2[i])%mod;
			// cerr << (d * p11[n-i-1]) << '\n';
			ans %= mod;
		}
		cout << ans << '\n';
	}
}