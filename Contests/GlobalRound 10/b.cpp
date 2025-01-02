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
		ll n,k;
		cin>>n>>k;
		vector<ll> a(n);
		ll mx = -1e18,mx2 = -1e18;
		for(int i=0;i<n;i++){
			cin>>a[i];
			mx = max(mx , a[i]);
		}
		k--;
		for(int i=0;i<n;i++){
			a[i] = mx - a[i];
			mx2 = max(mx2 , a[i]);
		}
		k %= 2;
		for(int i=0;i<n;i++){
			if(k)a[i] = mx2 - a[i];
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}