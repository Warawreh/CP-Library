#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	ll n,m;
	cin>>n>>m;
	multiset<pair<ll,ll>> st,nxt;
	for(ll i=0;i<m;i++){
		ll s;
		cin>>s;
		st.insert({s,1});
	}
	ll ans = 0;
	for(ll i=0;i<n;i++){
		vector<ll> bad;
		for(ll j=0;j<m;j++){
			ll x;
			cin>>x;
			if(st.find({x,0}) != st.end()){
				st.erase(st.find({x,0}));
				nxt.insert({x,0});
			}else if(st.find({x,1}) != st.end()){
				st.erase(st.find({x,1}));
				nxt.insert({x,1});
			}else{
				bad.push_back(x);
			}
		}
		// cerr << bad.size() << '\n';
		for(ll x : bad){
			assert(st.size());
			pair<ll,ll> cur = *st.begin();
			st.erase(st.begin());
			// cerr << x << ' ' << cur.first << ' ' << cur.second << '\n';
			if(cur.second == 0)ans++;
			nxt.insert({x , 0});
		}
		// cerr << '\n';
		st = nxt;
		nxt.clear();
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}