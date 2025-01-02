#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
ll ans = 0;
int n;

void calc(int i,string s){
	if(i == n){
		vector<ll> c(3);
		for(int j=0;j<n;j++){
			if(s[j] == 'a')c[0]++;
			else if(s[j] == 'b')c[1] = (c[1] + c[0])%mod;
			else if(s[j] == 'c')c[2] = (c[1] + c[2])%mod;
			else assert(0);
		}
		if(c[2])
			cerr << s << ' ' << c[2] << '\n';
		ans += c[2];
		return;
	}
	if(s[i] == '?'){
		s[i] = 'a';
		calc(i+1,s);
		s[i] = 'b';
		calc(i+1,s);
		s[i] = 'c';
		calc(i+1,s);
	}else{
		calc(i+1,s);
	}
}

int main(){
	fast
	string s;
	cin>>n>>s;
	calc(0,s);
	cout << ans << '\n';
}	