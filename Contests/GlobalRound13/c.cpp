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
		ll ans = 0;
		vector<ll> pre(n);
		ll hv = 0,ex = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i + 2 < n){
				pre[i + 2]++;
			}
			if(i + a[i] + 1 < n)pre[i+a[i]+1]--;
			if(i)pre[i] += pre[i-1];
			// ex = max(0LL,hv - a[i] + 1);
			// hv += ex;
		}
		for(int i=0;i<n;i++){
			hv += pre[i];
			ll use = min(a[i]-1 , hv);
			hv -= use;
			a[i] -= use;
			// cerr << a[i] << '\n';
			ans += a[i] - 1;
		}


		cout << ans << '\n';
	}
}