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
	vector<ll> ans;
	for(ll i=3;;i+=2){
		ll x = i*i - 1;
		assert(x%2 == 0);
		ans.push_back(x/2 + 1);
		if(x/2+ 1 > 1e9)break;
	}
	// cerr << ans.size() << '\n';
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout << upper_bound(all(ans) , n) - ans.begin() << '\n';
	}
}