#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res) % mod;
	if(b%2)res = (res * a)%mod;	
	return res;
}

int main(){
	fast
	#ifndef LOCAL
		freopen("xor.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		ll n = 0;
		// reverse(all(a));
		for(int i=0;i<a.size();i++){
			n = (n * 10)%(mod -1 );
			n += a[i] - '0';
			n %= (mod -1 );
		}
		if(n == 0)cout << "250000002\n";
		else cout << Pow(4,n-1) << '\n';
	}
}