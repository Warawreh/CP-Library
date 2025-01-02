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
	ll x,y;
	string s;
	cin>>s>>x>>y;
	ll n = s.size();
	vector<vector<int>> p(2,vector<int>(n));
	ll out = 0;
	for(ll i=0;i<n;i++){
		p[0][i] = (s[i] == '0') + (i ? p[0][i-1]: 0LL);
		p[1][i] = (s[i] == '1') + (i ? p[1][i-1]: 0LL);
		if(s[i] == '0'){
			out += p[1][i] * y;
		}else if(s[i] == '1'){
			out += p[0][i] * x;
		}
	}
	ll ans = 1e18;
	{// 1111111..0000..
		ll cur = out;
		ll q = 0,q2 = 0;
		for(int i=0;i<n;i++){
			if(s[i] == '?'){
				cur += p[1][i] * y + (p[1][n-1] - p[1][i]) * x;
				q++;
			}
		}
		ans = min(ans , cur);
		for(int i=0;i<n;i++){
			if(s[i] == '?'){
				cur -= p[1][i] * y + (p[1][n-1] - p[1][i]) * x + q2 * y;	
				q2++;
				cur += p[0][i] * x + (p[0][n-1] - p[0][i] + q - q2) * y;
				ans = min(ans , cur);
			}
		}
	}

	{// 0000..111111
		ll cur = out;
		ll q = 0,q2 = 0;
		for(int i=0;i<n;i++){
			if(s[i] == '?'){
				cur += p[0][i] * x + (p[0][n-1] - p[0][i]) * y;
				q++;
			}
		}
		ans = min(ans , cur);
		for(int i=0;i<n;i++){
			if(s[i] == '?'){
				cur -= p[0][i] * x + (p[0][n-1] - p[0][i]) * y + q2 * x;
				q2++;
				cur += p[1][i] * y + (p[1][n-1] - p[1][i] + q - q2) * x;
				ans = min(ans , cur);
			}
		}
	}

	cout << ans << '\n';
}