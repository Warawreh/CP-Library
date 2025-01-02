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
		vector<int> a(n);
		int ans = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i){
				int x = min(a[i] , a[i-1]);
				int b = max(a[i] , a[i-1]);
				// cerr << x << ' ' << b << '\n';
				while(x * 2 < b){
					x*=2;
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}