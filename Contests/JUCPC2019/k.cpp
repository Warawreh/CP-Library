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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	ll ans = 0;
	for(int i=0;i<(1<<n);i++){
		ll cur = 0;
		for(int j=0;j<n;j++){
			if((i>>j)&1)
				cur |= a[j];
		}
		ans += cur;
	}
	cout << ans << '\n';
}