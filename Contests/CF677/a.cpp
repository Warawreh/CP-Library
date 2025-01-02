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
		string n;
		cin>>n;
		int t = n[0] - '1';
		ll x = n.size();
		ll ans = 10 * t + x * (x+1)/2;
		cout << ans << '\n';
	}
}