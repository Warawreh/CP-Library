#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int SZ> struct HASH{
	const int mod = 1e9+7;
	int p[2] = {31,37};
	ll inv[2][SZ],POW[2][SZ],sum[2][SZ];
	ll Pow(ll a,ll b){
		if(!b)return 1;
		ll ret = Pow(a,b/2);
		if(b%2)return ((ret*ret)%mod*a)%mod;
		return (ret*ret)%mod;
	}	
	HASH(){
		POW[0][0] = POW[1][0] = 1;
		inv[0][0] = inv[1][0] = Pow(POW[0][0],mod-2);
		for(int i=1;i<SZ;i++){
			for(int x=0;x<2;x++){
				POW[x][i] = (POW[x][i-1] * p[x]) % mod;
				inv[x][i] = Pow(POW[x][i],mod-2);
			}
		}

	}
	void build(vector<int> s){
		for(int i=0;i<s.size();i++){
			for(int x=0;x<2;x++){
				sum[x][i+1] = ((s[i]) * POW[x][i])%mod;
				sum[x][i+1] = (sum[x][i+1] + sum[x][i]) %mod;
			}
		}
	}
	pair<int,int> check(int l,int r){
		if(l > r)return {0,0};
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

HASH<500005> h1,h2;


void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];


	if(a == b){
		if(k == 1)
			cout << "NO\n";
		else
			cout << "YES\n";
		return;
	}else{
		
		h1.build(a);
		h2.build(b);

		if(k == 0){
			cout << "NO\n";
			return;
		}
		bool can = false;
		for(int i=0;i<n;i++){
			int len = i;
			if(h1.check(0 , i) == h2.check(n-1-i,n-1) && h1.check(i+1,n-1) == h2.check(0,n-2-i)){
				can = true;
				break;
			}
		}

		if(!can){
			cout << "NO\n";
			return;
		}

		if(n > 2)
			cout << "YES\n";
		else{
			if(k % 2 == 1){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}