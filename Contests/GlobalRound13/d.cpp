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
		ll a,b;
		cin>>a>>b;
		ll x = __builtin_popcountll(a);
		ll y = __builtin_popcountll(b);
		bool good = true;
		ll cnt = 0;
		for(ll k=0;k<31;k++){
			if((b & (1<<k))){
				cnt--;
			}
			if((a & (1<<k)))cnt++;
			if(cnt < 0)good = false;
		}
		if(a <= b && good)cout << "Yes\n";
		else cout <<"No\n";
	}
}