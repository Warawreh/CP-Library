#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res) % mod;
	if(b%2)res = (res * a)%mod;
	return res;
}

int main(){
	fast
	int n;
	string s;
	cin>>n>>s;
	// s = string(n,'?');
	int q=0;
	for(char c : s)q += c == '?';
	vector<ll> ans(3);
	int bq = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'a')ans[0] = (ans[0] + Pow(3,bq))%mod ;
		if(s[i] == 'b')ans[1] = (ans[1] + ans[0])%mod;
		if(s[i] == 'c')ans[2] = (ans[2] + ans[1])%mod;
		if(s[i] == '?'){
			q--;
			vector<ll> tmp = ans;
			ans[2] = (ans[2] + ans[1])%mod;
			ans[1] = (ans[1] + ans[0])%mod;
			ans[0] = (ans[0] + Pow(3,bq))%mod ;
			for(int j=0;j<3;j++)ans[j] = (ans[j] + (tmp[j] * 2LL)%mod)%mod;
			bq++;
		}
		// for(ll i : ans)
		// 	cerr << i << ' ';
		// cerr << '\n';
	}
	cout << ans[2] << '\n';
}