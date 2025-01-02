#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<ll> a;

const int mod = 998244353;
const int nax = 5050;

ll dp[nax][nax];

ll fact[nax],inv[nax];

ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b%2)res = (res * a)%mod;
	return res;
}

ll calc(int i,int s){
	if(i == n){
		return !s;
	}
	if(s < 0)return 0;
	ll &ret = dp[i][s];
	if(ret != -1)return ret;
	ret = 0;
	int nxt = upper_bound(all(a) , a[i]) - a.begin();
	int take = nxt - i;
	if(nxt == n){
		if(s == 0)
			ret = (calc(nxt , s - 1 + take) * 1LL * inv[take-1])%mod;
	}else{
		ret = (calc(nxt,s + take) * 1LL * inv[take])%mod;
		if(s)
			ret = (ret + ((calc(nxt , s - 1 + take - 1) * 1LL * s)%mod * 1LL * inv[take-1]%mod))%mod;
	}
	return ret;

}

void solve(){

	cin>>n;


	a = vector<ll>(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j] = -1;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	ll ans = 0;
	ll bef = 1;

	for(int i=0;i<n;){

		int nxt = upper_bound(all(a) , a[i]) - a.begin();
		int s = i;
		int take = nxt - i - 1;

		bef = (bef * inv[take])%mod;

		ll cur = calc(nxt,s - 2 + take);
		cur = (cur * 1LL * s)%mod;
		cur = (cur * 1LL * (s - 1))%mod;

		cur = (cur * bef)%mod;
		ans = (ans + cur)%mod;

		bef = (bef * fact[take])%mod;
		bef = (bef * inv[take + 1])%mod;

		i = nxt;
		// cerr << i << ' ' << bef << '\n';

	}
	// assert(ans >= 0 && ans <= mod);
	cout << ans << '\n';

}

int main(){
	fast


	fact[0] = inv[0] = 1;
	for(int i=1;i<nax;i++){
		fact[i] = (fact[i-1] * 1LL * i)%mod;
		inv[i] = POW(fact[i] , mod-2);
	}


	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/