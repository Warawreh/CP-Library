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
    ll C,x,Start,n;
    cin>>C>>x>>Start>>n;
    vector<ll> t(3);
    for(ll i=0;i<3;i++)cin>>t[i];
    vector<vector<ll>> c(3);
	for(ll i=0;i<n;i++){
		ll time,taxi;
		cin>>time>>taxi;
		taxi--;
		c[taxi].push_back(time);
	}
	for(ll i=0;i<3;i++)sort(all(c[i]));

	ll ans = 0;
	for(ll T=0;T<3;T++){
		ll lo=0,hi = Start;
		while(lo <= hi){
			ll md = (lo + hi)/2;

			ll p=0,at = 0;
			ll i = 0;
			for(i=0;i<c[T].size();i++){
				ll cur = c[T][i];
				if(cur >= md)break;
				if(cur - at > x){
					at += ll((cur - at - 1) / x) * x;
					p = 0;
				}
				p++;

				if(p == C){
					at = cur;
					p = 0;
				}
			}


			ll arrive = Start+1;
			// cerr << T << ' ' << md << ' ' << at << ' ' << p << ' ' << arrive << '\n';

			if(md - at > x){
				p = 0;
				at += ll((md - at - 1) / x) * x;
			}

			p++;
			if(p == C){
				arrive = min(arrive , md + t[T]);
			}else{
				arrive = min(arrive , at + x + t[T]);
				for(;i<c[T].size();i++){
					ll cur = c[T][i];
					if(cur - at > x){
						break;
					}else{
						p++;
						if(p == C){
							arrive = min(arrive , cur + t[T]);
						}
					}
				}
			}

			if(arrive <= Start){
				lo = md+1;
				ans = max(ans , md);
			}else hi = md-1;
		}
	}
	cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/