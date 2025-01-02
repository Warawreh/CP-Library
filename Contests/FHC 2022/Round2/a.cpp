#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	string s;
	cin>>s;
	int n = s.size();
	vector<vector<ll>> pre(26,vector<ll>(n));
	for(ll i=0;i<n;i++){
		pre[s[i] - 'a'][i] = 1;
		if(i)
			for(ll j=0;j<26;j++){
				pre[j][i] += pre[j][i-1];
			}
	}
	ll q;
	cin>>q;
	ll ans = 0;
	while(q--){
		ll l,r;
		cin>>l>>r;
		if((r - l + 1) % 2 == 0)continue;
		if(l == r){
			ans++;
			continue;
		}
		l--;r--;
		ll odd=0,at = -1;
		for(ll i=0;i<26;i++){
			ll cur = pre[i][r] - (l ? pre[i][l-1] : 0);
			if(cur % 2 == 1){
				odd++;
				at = i;
			}
		}
		assert(odd);

		if(odd > 1)continue;
		// cerr << l << ' ' << r << ' ' << odd << ' ' << at << '\n';
		bool can = false;
		{//left is bigger
			ll md = (l + r)/2;
			bool good = true;
			for(ll i=0;i<26;i++){
				ll left = pre[i][md] - (l ? pre[i][l-1] : 0);
				ll right = pre[i][r] - pre[i][md];
				if(i == at){
					assert((left + right)%2 == 1);
					if(left - 1 != right){
						good = false;
						break;
					}
				}else{
					assert((left + right)%2 == 0);
					if(left != right){
						good = false;
						break;
					}
				}
			}
			if(good)can = true;
		}
		{//right is bigger
			ll md = (l + r)/2 - 1;
			bool good = true;
			for(ll i=0;i<26;i++){
				ll left = pre[i][md] - (l ? pre[i][l-1] : 0);
				ll right = pre[i][r] - pre[i][md];
				if(i == at){
					assert((left + right)%2 == 1);
					if(left + 1 != right){
						good = false;
						break;
					}
				}else{
					assert((left + right)%2 == 0);
					if(left != right){
						good = false;
						break;
					}
				}
			}
			if(good)can = true;
		}

		ans += can;

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