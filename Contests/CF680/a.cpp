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
		vector<pair<int,int>> v;
		for(ll i = 2;i*i<=b;i++){
			int c = 0;
			while(b % i == 0){
				b /= i;
				c++;
			}
			if(c){
				v.push_back({i,c});
			}
		}
		if(b > 1)v.push_back({b,1});
		ll ans = 1;
		ll aa = a;
		for(pair<int,int> x : v){
			int i = x.first;
			int cnt = 0;
			while(a % i == 0){
				a /= i;
				cnt++;
			}
			int c = x.second;
			// cerr << i << ' ' << c << ' ' << cnt << '\n';
			if(c > cnt)ans = aa;
			else{
				ll nxt = aa / pow(i , cnt - c + 1);
				// cerr << nxt << '\n';
				ans = max(ans ,nxt);
			}
		}
		cout << ans << '\n';
	}
}