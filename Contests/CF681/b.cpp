#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n),b(k),bad(n),at(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]--;
			at[a[i]] = i;
		}
		for(int i=0;i<k;i++){
			cin>>b[i];
			b[i]--;
			bad[b[i]] = 1;
		}
		set<pair<int,int>> st;
		for(int i=0;i<n;i++){
			st.insert({i,bad[a[i]]});
		}
		ll ans = 1;
		for(int i=0;i<k;i++){
			int v = 2;
			auto it = st.upper_bound({at[b[i]] , 2});
			if(it != st.end()){
				// cerr << i << ' ' << it->first << '\n';
				v -= it->second;
			}else{
				v--;
			}
			it--;
			if(it == st.begin()){
				v--;
			}else{
				it--;
				v -= it->second;
			}
			// cerr << v << '\n';
			ans = (ans * v)%mod;
			st.erase({at[b[i]] , 1});
		}
		cout << ans << '\n';

	}
}