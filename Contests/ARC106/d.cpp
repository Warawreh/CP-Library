#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int nax = 2e5 + 10;
const int kax = 303;

ll inv[kax],P[nax][kax];

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}

void A(ll &a,ll b){
	a += b;
	a%=mod;
	a+=mod;
	a%=mod;
	// if(a >= mod)a -=mod;
	// if(a < 0)a +=mod;
}

int main(){
	fast
	ll n,k;
	cin>>n>>k;

	for(ll i=1;i<=k;i++)inv[i] = Pow(i , mod-2);

	vector<ll> a(n);
	for(ll i=0;i<n;i++)cin>>a[i];

	for(ll i=0;i<n;i++){
		P[i][0] = 1;
		for(ll j=1;j<=k;j++)P[i][j] = (P[i][j-1] * a[i])%mod;
	}

	vector<vector<ll>> sum(k + 1,vector<ll>(n,1));
	for(ll p=1;p<=k;p++){
		sum[p][n-1] = 0;
		for(ll i=n-2;i>=0;i--){
			sum[p][i] = (sum[p][i+1] + Pow(a[i + 1] , p))%mod;
		}
	}
	for(ll p=1;p<=k;p++){
		ll ans = 0;
		// cerr << p << '\n';
		ll cur = 1,v = p;
		for(ll j=1;j<=p;j++){
			cur = (cur * v)%mod;
			cur = (cur * inv[j])%mod;
			v--;
			for(ll i=0;i<n;i++){
				A(ans , (cur * (sum[p-j][i] * P[i][j])%mod)%mod);
				// cerr << i << " : \n";
				// cerr << j << ' ' << cur << ' ' << sum[p-j][i] << ' ' << P[i][j] << '\n';
			}
		}
		A(ans , ((sum[p][0] + P[0][p])%mod*(n-2)%mod));
		cout << ans << '\n';
	}
}