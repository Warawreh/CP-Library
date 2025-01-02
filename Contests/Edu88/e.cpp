#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353 ;
const int COM_LEN = 1e6 + 10;
ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res) % mod;
	if(b%2)res = (res * a)%mod;
	return res;
}
ll fac[COM_LEN],inv[COM_LEN];
void init_COM(){
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i=2;i<COM_LEN;i++){
		fac[i] = (fac[i-1] * i) % mod;
		inv[i] = Pow(fac[i] , mod-2);
	}
}
inline ll nCk(ll n, ll k){
	return ((fac[n] * inv[k])%mod * inv[n-k])%mod;
}
inline ll nPk(ll n,ll k){
	return (fac[n]*inv[n-k])%mod;
}

/*
	Put in the begin of the code
		init_COM() 
	COM_LEN = The size of the numbers
*/

int main(){
	fast
	init_COM();
	int n,k;
	cin>>n>>k;
	if(k > n){
		cout << 0 << '\n';
		return 0;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ll total = n / i;
		if(total >= k)
			ans += nCk(total - 1, k - 1);
		ans %= mod;
	}
	cout << ans << '\n';
}