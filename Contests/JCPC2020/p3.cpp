#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define mk make_pair 
#define ff first 
#define ss second 
typedef long long ll;
const int mod =1e9+7;
const int COM_LEN = 1e5 + 10;

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
	// freopen("xor.in","r",stdin);
	init_COM();	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll even=0,odd=0;
		for(int i=0;i<n;i++){
			if(i%2) odd = (odd+nCk(n,i))%mod;
			else even = (even +nCk(n,i))%mod;
		}
		ll ans =(odd*(odd+1)/2)%mod;
		ans = (ans+(even*(even+1)/2)%mod)%mod;
		cout<<ans<<"\n";	
		
	}
	return 0;
}
