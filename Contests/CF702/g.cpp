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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<ll> a(n),x(m),pre(n);
		vector<ll> mx(n);
		int at = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			pre[i] = a[i] + (i ? pre[i-1] : 0LL);
			mx[i] = max(pre[i] , (i ? mx[i-1] : (ll)-1e18));
			if(pre[at] < pre[i])at = i;
		}
		for(int i=0;i<m;i++){
			cin>>x[i];
			ll ans = 0;
			if(x[i] > pre[at]){
				if(pre.back() <= 0){
					cout << -1 << ' ';
					continue;
				}else{
					ll need = (x[i] - pre[at] + pre.back() - 1) / pre.back();
					ans = n*need;
					x[i] = x[i] - pre.back() * need;
				}
			}
			assert(x[i] >= 0);
			if(x[i] == 0){
				ans--;
			}else{
				int lo=0,hi=n-1,to = 0;
				while(lo <= hi){
					int md = (lo + hi)/2;
					if(mx[md] >= x[i]){
						to = md;
						hi = md-1;
					}else lo = md+1;
				}
				ans += to;
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}
