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
		multiset<ll> st;
		ll ans = 0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			st.insert(x);
		}
		while(st.size() > 1){
			ll a = *st.begin();
			st.erase(st.begin());
			ll b = *st.begin();
			st.erase(st.begin());
			ans += a+b;
			st.insert(a+b);
		}
		cout << ans << '\n';
	}
}
