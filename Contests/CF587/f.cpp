#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 3e5;
vector<ll> rem[nax];

int main(){
	fast
	ll n,k;
	string s;
	cin>>n>>k>>s;
	vector<ll> dp(n+1,1e18);
	vector<ll> b;
	multiset<ll> st;
	int at=0;
	b.push_back(0);
	dp[0] = 0;
	for(ll i=1;i<=n;i++){
		dp[i] = min(dp[i] , i + dp[i-1]);
		if(st.size()){
			dp[i] = min(dp[i] , *st.begin());
		}
		while(at < b.size() && b[at] + k + 1 < i)at++;
		// cerr << i << ' ' << (at < b.size() ? dp[b[at]] : -1) << ' ' << i << '\n';
		if(s[i-1] == '1'){
			ll cost = i;
			if(at < b.size())cost += min(dp[i] , dp[b[at]]);
			st.insert(cost);
			dp[i] = min(dp[i] , cost);
			rem[min(n,i+k)].push_back(cost);
		}
		while(at < b.size() && dp[b[at]] >= dp[i])b.pop_back();
		for(ll j : rem[i])st.erase(st.find(j));
		// cerr << dp[i] << '\n';
		b.push_back(i);
	}
	cout << dp.back() << '\n';
}