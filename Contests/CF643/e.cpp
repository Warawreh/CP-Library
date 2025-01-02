#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll a,r,m;
vector<ll> pre,b;

ll calc(ll h){
	ll at = lower_bound(all(b) , h) - b.begin();
	ll up = h * at - (at ? pre[at-1] : 0ll);
	ll down = (pre[n] - (at ? pre[at-1] : 0ll)) - (n - at) * h ;
	// cerr << up << ' '<< down << '\n';
	ll cost = 0;
	if(r + a > m){
		ll g = min(up , down);
		up -= g;
		down -= g;
		cost += g *m;
	}
	cost += up * a;
	cost += down * r;
	return cost;
}

int main(){
	fast
	cin>>n>>a>>r>>m;
	if(!a || !r){
		cout << 0 << '\n';
		return 0;
	}
	b = vector<ll>(n);
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>b[i];
		sum += b[i];
	}
	sum /= n;
	sort(all(b));
	pre = b;
	for(int i=1;i<n;i++)pre[i] += pre[i-1];
	pre.push_back(pre.back());
	ll ans = 1e18;
	for(ll i : b)ans = min(ans,calc(i));
	for(ll i=max(0ll,sum-n);i<=sum+n;i++)ans = min(ans,calc(i));
	cout << ans << '\n';
}