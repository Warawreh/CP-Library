#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;
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
	if(k > n)return 0;
	return ((fac[n] * inv[k])%mod * inv[n-k])%mod;
}
inline ll nPk(ll n,ll k){
	return (fac[n]*inv[n-k])%mod;
}


void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll> a(n);
	vector<ll> h(n + 4);
	for(ll i=0;i<n;i++){
		cin>>a[i];
		h[a[i]]++;
	}
	for(int i=2;i<=n;i++)h[i] += h[i-1];
	ll ans = 0;
	for(ll i=1;i<=n;i++){
		if(h[i] == 0)continue;
		// cerr << ans << '\n';
		ll l = i,r = i+k;
		r = min(r,n);
		cerr << l << ' ' << r << '\n';
		if(h[r] - h[l-1] >= m)
			ans = (ans + (nCk(h[r] - h[l-1] , m) - nCk(h[r] - h[l] , m) + mod) % mod)%mod;
	}
	cout << ans << '\n';
}

int main(){
	fast
	init_COM();
	int t;
	cin>>t;
	while(t--)solve();
}