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
	#ifndef LOCAL
		freopen("falafel.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		ll n,m,l;
		cin>>n>>m>>l;
		vector<ll> t(n);
		for(int i=0;i<n;i++){
			cin>>t[i];
		}
		sort(all(t));
		ll lo=1,hi=1e18,ans = 1e18;
		while(lo <= hi){
			ll md = (lo + hi)/2;
			ll can = 0;
			for(int i=0;i<n;i++){
				if(can >= m)break;
				can += md / (l * t[i]);
			}
			// cerr << can << '\n';
			if(can >= m){
				hi = md-1;
				ans = md;
			}else lo = md+1;
		}
		cout << ans << '\n';
	}
}