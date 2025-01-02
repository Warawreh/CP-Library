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
	string s;
	cin>>s;
	int n = s.size();
	ll x = 0;
	string ans;
	vector<ll> p = {1,10,100,1000,10000,100000};
	ll at = 0;
	for(int i=n-1;i>=0;i--){
		int c = s[i] - '0';
		int bf = x;
		x += c * p[at];
		at++;
		bool good = false;
		ll g = 1;
		if(x < 0 || bf > 7){
			good = true;
			bf = -1;
		}
		for(int j=0;j<bf;j++){
			if(g * c > x){
				good = true;
				break;
			}
			g*=c;
		}
		// cerr << g << ' ' << x << ' ' << good << '\n';
		if(good && c != 1){
			ans += '*';
			ans += '*';
			ans += s[i];
			x=-1e9;
			at=0;
		}else{
			ans+=s[i];
		}
		// cerr << ans << '\n';
	}
	reverse(all(ans));
	cout << ans << '\n';
}