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
		ll p,f,cnts,cntw,s,w;
		cin>>p>>f>>cnts>>cntw>>s>>w;
		if(s > w){
			swap(w,s);
			swap(cnts,cntw);
		}
		ll ans = 0;
		for(int i=0;i<=cnts;i++){
			ll tots = i * s;
			if(tots > p)break;
			ll can = (p - tots)/w;
			can = min(can , cntw);
			ll cur = i + can;

			ll ns = cnts - i;
			ll nw = cntw - can;

			ll take = min(f / s , ns);
			tots = take * s;
			cur += take;
			cur += min(ll((f - tots)/w) , nw);
			ans = max(ans , cur);
		}
		cout << ans << '\n';
	}
}