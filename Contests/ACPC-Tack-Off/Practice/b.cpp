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
	freopen("mult.in","r",stdin);
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> a(n);
		for(ll i=0;i<n;i++)cin>>a[i];
		sort(all(a));
		ll ans = 1;
		for(int i=n-k;i<n;i++)ans *= a[i];
		cout << ans << '\n';
	}
}