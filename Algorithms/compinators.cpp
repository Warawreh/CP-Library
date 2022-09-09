/*
Name: nCk & nPk
Description: Counting things
Time: O(NLogN) to initilize the arrays and O(1) for nCk/nPk
Space: O(n + n) to save both arrays
*/
vector<ll> fact,inv;
void init_COM(int n){
	factt = inv = vector<ll>(n+1);
	fact[0] = inv[0] = 1;
	for(int i=1;i<=n;i++){
		fact[i] = (fact[i-1] * i) % mod;
		inv[i] = Pow(fact[i] , mod-2);
	}
}
inline ll nCk(ll n, ll k){
	return ((fact[n] * inv[k])%mod * inv[n-k])%mod;
}
inline ll nPk(ll n,ll k){
	return (fact[n]*inv[n-k])%mod;
}
