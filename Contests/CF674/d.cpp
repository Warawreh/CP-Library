#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	ll n;
	cin>>n;
	map<ll,ll> hv;
	ll l = 0;
	vector<ll> pre(n);
	ll ans = 0;
	for(ll i=0;i<n;i++){
		ll a;
		cin>>a;
		pre[i] = (i ? pre[i-1] : 0) + a;
		if(hv[pre[i]] || pre[i] == 0){
			ans++;
			while(l < i){
				hv[pre[l]] = 0;
				l++;
			}
			pre[i] = a;
		}
		hv[pre[i]] = 1;
	}
	cout << ans << '\n';
}