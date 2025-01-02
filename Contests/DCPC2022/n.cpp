#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}

vector<ll> fact,inv;
void init_COM(int n){
   fact = inv = vector<ll>(n+1);
   fact[0] = inv[0] = 1;
   for(int i=1;i<=n;i++){
      fact[i] = (fact[i-1] * i) % mod;
      inv[i] = POW(fact[i] , mod-2);
   }
}
inline ll nCk(ll n, ll k){
	return ((fact[n] * inv[k])%mod * inv[n-k])%mod;
}
inline ll nPk(ll n,ll k){
	return (fact[n]*inv[n-k])%mod;
}


int main(){
    fast

    init_COM(2e5 + 10);

    int t;
    cin>>t;
    while(t--){
    	ll n,m,a,b,k;
    	cin>>n>>m>>a>>b>>k;
    	ll d2 = POW(POW(2 , mod-2) , k);
    	ll tot = 0;
    	for(ll i=1;i<=k;i++){
    		ll ways = (nCk(k , i) * 1LL * d2)%mod;

    		ll rest = k - i;
    		ll x = i / a;
    		ll y = rest / b;
    		x = min(x , n);
    		y = min(y , m);
    		// cerr << ways << '\n';
    		tot = (tot + ((x * y)%mod * ways)%mod)%mod;

    	}
    	// cerr << tot << '\n';
    	cout << ((n * m)%mod - tot + mod)%mod << '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/