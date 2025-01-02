#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

void solve(){
	ll n;
	string s;
	cin>>n>>s;
	ll ans = 0;
	ll lst = 0;
	if(s[0] != 'F')lst = 1;
	for(ll i = 1;i<n;i++){
		ll nVal = lst;
		if(s[i] == 'F'){
			s[i] = s[i-1];	
		}else{
			nVal = i+1;
		}
		if(s[i] == 'F' || s[i-1] == 'F'){
			lst = nVal;
			continue;
		}
		if(s[i] != s[i-1]){
			ans = (ans + (lst * (n - i))%mod)%mod;
		}
		lst = nVal;
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