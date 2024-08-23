/*
Name: hashing for strings and arrays
Description: transform array/string to an integer with low prop of collision (change primes or mod)
Time: O(NLogN) to init arrays and O(1) to get the value
Space: O(2N) for 2 primes
*/

const int mod = 1e9+7;
const int SZ = 1e6;

int p[2] = {31,37};
ll inv[2][SZ],POW[2][SZ],
int Pow(int a,int b){
    if(!b)return 1;
    int ret = Pow(a,b/2);
    if(b%2)return ((ret*1LL*ret)%mod*1LL*a)%mod;
    return (ret*1LL*ret)%mod;
} 
void init(){
    POW[0][0] = POW[1][0] = 1;
    inv[0][0] = inv[1][0] = Pow(POW[0][0],mod-2);
    for(int i=1;i<SZ;i++){
        for(int x=0;x<2;x++){
            POW[x][i] = (POW[x][i-1] * 1LL * p[x]) % mod;
            inv[x][i] = Pow(POW[x][i],mod-2);
        }
    }
}

template<int SZ> struct HASH{
	int sum[2][SZ];
	
	void build(string s){
		for(int i=0;i<s.size();i++){
			for(int x=0;x<2;x++){
				sum[x][i+1] = ((s[i] - 'a' + 1) * POW[x][i])%mod;
				sum[x][i+1] = (sum[x][i+1] + sum[x][i]) %mod;
			}
		}
	}
	pair<int,int> check(int l,int r){
		ll h1 = ((sum[0][r+1] - sum[0][l] + mod)%mod * inv[0][l])%mod;
		ll h3 = ((sum[1][r+1] - sum[1][l] + mod)%mod * inv[1][l])%mod;
		return {h1,h3};
	}
	bool check(int l1,int r1,int l2,int r2){
		ll h1 = ((sum[0][r1+1] - sum[0][l1] + mod)%mod * inv[0][l1])%mod;
		ll h2 = ((sum[0][r2+1] - sum[0][l2] + mod)%mod * inv[0][l2])%mod;
		ll h3 = ((sum[1][r1+1] - sum[1][l1] + mod)%mod * inv[1][l1])%mod;
		ll h4 = ((sum[1][r2+1] - sum[1][l2] + mod)%mod * inv[1][l2])%mod;
	  	return h1==h2 && h3==h4;
	}

};
