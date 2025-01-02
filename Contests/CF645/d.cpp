#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> sum,pre;

int main(){
	fast
	ll n,m;
	cin>>n>>m;
	sum.resize(2*n);
	pre.resize(2*n);
	vector<ll> a(2*n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<2*n;i++){
		if(i >= n)a[i] = a[i-n];
		sum[i] = a[i] * (a[i]+1)/2 + (i ? sum[i-1] : 0ll);
		pre[i] = a[i] + (i ? pre[i-1] : 0ll);
	}
	// cerr << pre[9] << '\n';
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(a[i] >= m){
			cerr << i << '\n';
			ll val = a[i] * (a[i] + 1) / 2;
			ll need = a[i] - m;
			val -= need * (need + 1)/2;
			ans = max(ans , val);
			continue;
		}
		int md,lo=i,hi=2*n-1,at=i;
		ll rest = 0;
		while(lo <= hi){
			md = (lo + hi)/2;
			ll cur = pre[md] - (i ? pre[i-1] : 0ll);
			if(cur <= m){
				lo = md+1;
				at = md;
				rest = m - cur;
			}else hi = md-1;
		}
		if(at == 2*n-1 && rest)continue;
		ll val = sum[at] - (i ? sum[i-1] : 0ll);
		if(rest){
			ll need = min(a[i] , a[at + 1] - rest);
			ll to = rest + need;
			// cerr << i << ' ' << at << ' ' << rest << ' ' << val << ' ' << need << '\n';
			// break;
			val += to * (to + 1)/2;
			val -= need * (need + 1)/2;
		}
		ans = max(ans, val);
	}
	cout << ans << '\n';
}