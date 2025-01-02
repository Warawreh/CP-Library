#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

const int COM_LEN = 5e5 + 10;
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


int main(){
	fast
	init_COM();
	int n;
	cin>>n;
	vector<int> a(2*n);
	for(int i=0;i<2*n;i++)cin>>a[i];
	sort(all(a));
	ll sum = 0;
	for(int i=0;i<2*n;i++){
		if(i < n)sum = (sum - a[i] + mod)%mod;
		else sum = (sum + a[i])%mod;

	}
	cout << (sum * nCk(2*n,n))%mod  << '\n';
}