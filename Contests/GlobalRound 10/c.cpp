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
		int n;
		cin>>n;
		vector<ll> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		ll ans = 0;
		for(int i=n-2;i>=0;i--){
			ans += max(a[i] - a[i+1] , 0LL);
		}
		cout << ans << '\n';
	}
}