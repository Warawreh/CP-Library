#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
vector<ll> p2;

void A(ll &a,int b){
	a += b;
	if(a >= mod)a -= mod;
	if(a < 0)a += mod;
}

ll mul(ll a,ll b){
	a *= b;
	a %= mod;
	return a;
}

void solve(){
	int n;
	cin>>n;
	vector<ll> cnt(62);
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int b=0;b<61;b++){
			if((a[i] >> b) & 1)cnt[b]++;
		}
	}
	for(int i=0;i<61;i++)cnt[i] = mul(cnt[i] , p2[i]);
	vector<ll> add(62,0);
	ll ans = 0;	
	for(int i=0;i<n;i++){
		ll give = 0;
		for(int b=0;b<61;b++){
			if((a[i] >> b) & 1){
				ll x = a[i]%mod;
				A(ans , mul(mul(x , cnt[b]),n) );
				A(give , cnt[b]);
			}
		}	
		for(int b=0;b<61;b++){
			if(((a[i] >> b) & 1) == 0){
				A(add[b] , give);
			}
		}	
	}
	for(int i=0;i<n;i++){
		for(int b=0;b<61;b++){
			if((a[i] >> b) & 1){
				A(ans , mul(p2[b] , add[b]));
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	fast
	p2.resize(62);
	p2[0] = 1;
	for(int i=1;i<62;i++)p2[i] = (p2[i-1] * 2LL)%mod;
	int t;
	cin>>t;
	while(t--)solve();
}