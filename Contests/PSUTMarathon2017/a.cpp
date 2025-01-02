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
	int n;
	cin>>n;
	vector<ll> pre(n),pp(n),suf(n),ss(n),a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		pre[i] = a[i] + (i ? pre[i-1] : 0LL);
		pp[i] = pre[i] + (i ? pp[i-1] : 0LL);
	}
	for(int i=n-1;i>=0;i--){
		suf[i] = a[i] + (i+1<n ? suf[i+1] : 0LL);
		ss[i] = suf[i] + (i+1<n ? ss[i+1] : 0LL);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		int lo = i,hi=n-1,at = i;
		cerr << i << ' ';
		while(lo <= hi){
			int md = (lo + hi)/2;
			ll sum1 = pre[md] - pre[i];
			ll sum2 = suf[md] + (i ? pre[i-1] : 0LL) + a[n-1];
			if(sum1 <= sum2){
				at = md;
				lo = md+1;
			}else hi = md-1;
		}
		for(int x=i;x<at;x++)ans += pre[x] - (i ? pre[i-1] : 0LL);
		for(int x=n-2;x>=at;x--)
		cerr << at << ' ' << pp[at-1] << ' ' << (i ? pp[i - 1] : 0LL) << '\n';
		// ans += pp[at-1] - (i ? pp[i - 1] : 0LL) - (i ? pre[i-1] * (n - i - 1) : 0LL) + (at < n ? ss[at] : 0LL);
	}
	cout << ans << '\n';
}