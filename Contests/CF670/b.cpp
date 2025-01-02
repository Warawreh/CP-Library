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
		vector<ll> a,b;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x < 0)a.push_back(x);
			else b.push_back(x);
		}
		sort(all(a));
		sort(all(b));
		reverse(all(b));
		ll cur = 1;
		ll ans = -1e18;
		for(int i=0;i<=5;i++){
			int need = 5 - i;
			ll val = cur;
			if(b.size() >= need){
				for(int j=0;j<need;j++){
					val *= b[j];
				}
				ans = max(ans , val);
			}

			if(i >= a.size())break;
			cur *= a[i];
		}
		reverse(all(a));
		cur = 1;
		for(int i=0;i<=5;i++){
			int need = 5 - i;
			ll val = cur;
			if(b.size() >= need){
				for(int j=0;j<need;j++){
					val *= b[j];
				}
				ans = max(ans , val);
			}

			if(i >= a.size())break;
			cur *= a[i];
		}
		cout << ans << '\n';
	}	
}