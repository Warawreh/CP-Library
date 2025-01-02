#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}

void A(ll &a,ll b){
	a += b;
	if(a >= mod)a -=mod;
	if(a < 0)a +=mod;
}


int main(){
	fast
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(int p=1;p<=k;p++){
		ll ans = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<i;j++){
				A(ans , Pow(a[i] + a[j] , p));
			}
		cout << ans << '\n';
	}
}