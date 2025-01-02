#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

int main(){
	fast
	int n;
	string s = "AAAA";
	cin>>n>>s[0]>>s[1]>>s[2]>>s[3];
	if(s == "AAAA" || s == "AAAB" || s == "AABA" || s == "AABB" || s == "ABAB" 	|| s == "ABBB" || s == "BBAB" || s == "BBBB" )
		cout << 1 << '\n';
	else if(s == "ABAA" || s == "BABA" || s == "BABB" || s == "BBAA" ){
		ll ans = 1;
		for(int i=0;i<n-3;i++)
			ans = (ans * 2)%mod;
		cout << ans << '\n';
	}else{
		ll a=1,b=1;
		for(int i=0;i<n-3;i++){
			swap(a,b);
			b = (b+a)%mod;
		}
		cout << b << '\n';
	}

}