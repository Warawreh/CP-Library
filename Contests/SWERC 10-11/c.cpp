#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

const int mod = 1e9+7;
int p[2] = {31,37};
const int nax = 1010;
ll inv[2][nax],POW[2][nax];
ll Pow(ll a,ll b){
	if(!b)return 1;
	ll ret = Pow(a,b/2);
	if(b%2)return ((ret*ret)%mod*a)%mod;
	return (ret*ret)%mod;
}	
void init(){
	POW[0][0] = POW[1][0] = 1;
	inv[0][0] = inv[1][0] = Pow(POW[0][0],mod-2);
	for(int i=1;i<nax;i++){
		for(int x=0;x<2;x++){
			POW[x][i] = (POW[x][i-1] * p[x]) % mod;
			inv[x][i] = Pow(POW[x][i],mod-2);
		}
	}

}
template<int SZ> struct HASH{
	ll sum[2][SZ];
	void build(vector<int> s){
		reverse(all(s));
		for(int i=0;i<s.size();i++){
			// cerr << s[i] << ' ';
			for(int x=0;x<2;x++){
				sum[x][i+1] = ((s[i] ) * POW[x][i])%mod;
				sum[x][i+1] = (sum[x][i+1] + sum[x][i]) %mod;
			}
		}
		// cerr << '\n';
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


HASH<1010> vals[1010],res;

void solve(){
	vector<vector<int>> a(n,vector<int>(n)),b(n,vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
		vals[i].build(a[i]);
		// cerr << vals[i].check(0,n-1).first << ' ' << vals[i].check(0,n-1).second << '\n';
	}

	vector<pair<ll,ll>> answer(n),myans(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>b[i][j];
		res.build(b[i]);
		answer[i] = res.check(0,n-1);
		// cerr << answer[i].first << ' ' << answer[i].second << '\n';
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pair<ll,ll> cur = vals[j].check(0,n-1);
			// if(i==0)cerr << cur.first << ' ' << cur.second << '\n';
			myans[i] = {(myans[i].first + (cur.first * a[i][j])%mod)%mod , (myans[i].second + (cur.second * a[i][j])%mod)%mod};
		}
	}
	// cerr << myans[0].first<< ' ' << myans[0].second<< '\n';
	
	bool good = true;
	for(int i=0;i<n;i++){
		if(myans[i] != answer[i])good = false;
		// cerr << answer[i].first << ' ' << answer[i].second << '\n';
		// cerr << myans[i].first << ' ' << myans[i].second << '\n';
	}
	cout << (good ? "YES\n" : "NO\n");

}

int main(){
	fast
	init();
	while(1){
		cin>>n;
		if(n==0)break;
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/