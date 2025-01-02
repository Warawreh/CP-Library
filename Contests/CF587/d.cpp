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
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)cin>>a[i];
	sort(all(a));
	ll g = 0;
	ll sum = 0;
	for(ll i=0;i<n;i++){
		g = __gcd(g , a.back() - a[i]);
		sum += a.back() - a[i];
	}
	ll y = sum / g;
	cout << y << ' ' << g << '\n';
}