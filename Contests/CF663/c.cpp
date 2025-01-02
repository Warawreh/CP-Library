#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res)%mod;
	if(b%2)res = (res * a)%mod;
	return res;
}

int main(){
	fast
	int n;
	cin>>n;
	vector<ll> f(n+1);
	f[0] = 1;
	for(int i=1;i<=n;i++){
		f[i] = (f[i-1] * 1LL * i)%mod;
	}
	cout << (f[n] - Pow(2,n-1) + mod)%mod << '\n';
}