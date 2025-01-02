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
	#ifndef LOCAL
		freopen("cakes.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		ll m;
		cin>>n>>m;
		vector<pair<ll,ll>> c(n);
		for(int i=0;i<n;i++)cin>>c[i].first;
		for(int i=0;i<n;i++)cin>>c[i].second;
		sort(all(c));
		int ans = 0;
		multiset<ll> st;
		ll sum = 0;
		for(int i=0;i<n;i++){
			sum += c[i].second;
			ll at = c[i].first;
			st.insert(-c[i].second);
			if(at > m)break;
			while(st.size() && sum + at > m){
				sum += *st.begin();
				st.erase(st.begin());
			}
			// cout << at << ' ' << st.size() << '\n';
			ans = max(ans ,(int)st.size());
		}
		cout << ans << '\n';
	}
}