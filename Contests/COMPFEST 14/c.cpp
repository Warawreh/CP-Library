#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 3e5 + 10;
const int mod = 998244353;

ll fact[nax],inv[nax];

ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}

ll nPk(ll n,ll k){
	if(k > n)return 0;
	return (fact[n] * inv[n-k])%mod;
}

ll nCk(ll n,ll k){
	if(k > n)return 0;
	return ((fact[n] * inv[n-k])%mod * inv[k])%mod;
}

int main(){
	fast


	fact[0] = inv[0] = 1;
	for(int i=1;i<nax;i++){
		fact[i] = (fact[i - 1] * 1LL * i)%mod;
		inv[i] = POW(fact[i] , mod-2);
	}

	int n,m;
	cin>>n>>m;
	vector<ll> a(n);

	ll tot = 0;
	map<ll,bool> hv;
	for(int i=0;i<n;i++){
		cin>>a[i];

		hv[tot] = 1;
		tot += a[i];
	}

	ll d = 0;
	if(tot % 2 == 0){
		tot /= 2;
		ll cur = 0;
		for(int i=0;i<n;i++){
			if(hv[cur + tot] == 1)d++;
			cur += a[i];
		}
	}

	ll s = n - d*2;
	ll ans = 0;

	for(int take = 0;take <= min(m + 0LL, d);take++){
		int rem = d - take;
		int curC = m - take;

		ll v = (nPk(m , take) * nCk(d , take))%mod;
		ans = (ans + ((POW(curC , s) * POW(nPk(curC , 2) , rem) )%mod  * v)%mod )%mod;
	}

	cout << (ans)%mod << '\n';
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/

/*
 [1,1,2,1]
 [1,1,2,2]
 [1,2,2,1]
 [1,2,2,2]
 [2,1,1,1]
 [2,1,1,2]
 [2,2,1,1]
 [2,2,1,2]

 [2,1,2,1]
 [1,2,1,2]
*/