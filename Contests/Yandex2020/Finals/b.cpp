#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<vector<ll>,int> cnt;

int main(){
	fast
	int n;
	cin>>n;
	ll ans = 0;
	vector<pair<ll,ll>> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
		for(int j=0;j<i;j++){
			// cerr << "Points : " << i << ' ' << j << '\n';
			ll a = p[i].second - p[j].second;
			ll b = p[i].first - p[j].first;
			if(b < 0){
				a = -a;
				b = -b;
			}
			ll c = gcd(a,b);
			a /= c;
			b /= c;
			if(b == 0)a=0;
			{
				ll x = a * (-p[i].first) + p[i].second * b;
				ll y = b;
				if(y < 0){
					x = -x;
					y = -y;
				}
				if(y == 0)x = p[i].first;
				ll g = gcd(x,y);
				if(g){
					x/=g;
					y/=g;
				}
				// cerr << '!' << a << ' ' << b << ' ' << x << ' ' << y << '\n';
				ans += cnt[{a,b}] - cnt[{a,b,x,y}] - (x > y ? cnt[{a,b,a*a+b*b}] : 0) + cnt[{a,b,a*a+b*b,x,y}];
				// cerr << cnt[{a,b}] - cnt[{a,b,x,y}] - cnt[{a,b,a*a+b*b}] + cnt[{a,b,a*a+b*b,x,y}] << '\n';
				// cerr << cnt[{a,b}] << ' ' << cnt[{a,b,x,y}] << ' ' << cnt[{a,b,a*a+b*b}] << ' ' << cnt[{a,b,a*a+b*b,x,y}] << '\n';
				cnt[{a,b,a*a+b*b}]++;//3
				cnt[{a,b,a*a+b*b,x,y}]++;//5
				cnt[{a,b,x,y}]++;//4
				cnt[{a,b}]++;//2
			}
			// ans += s[make_pair(a,b)] - po[i][make_pair(a,b)] - po[j][make_pair(a,b)];
			// s[make_pair(a,b)]++;
			// po[i][make_pair(a,b)]++;
			// po[j][make_pair(a,b)]++;
			// cerr << "Slop : "<< a << ' ' << b << '\n';
		}
	}
	cout << ans << '\n';
}