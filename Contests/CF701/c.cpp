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
		ll x,y;
		cin>>x>>y;
		ll ans = 0;
		for(ll i=1;i*i<=x&&i<=y;i++){
			ll lo=i,hi=y,to=-1;
			while(lo <= hi){
				ll md = (lo + hi)/2;
				if((md + 1) * i <= x){
					lo = md + 1;
					to = md;
				}else hi = md-1;
			}
			if(to != -1)ans += to - i ;
			else break;
		}
		cout << ans << '\n';
	}
}