#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 12;
bitset<nax> c,a,x;

int main(){
	fast
	string s;
	cin>>s;
	int n = s.size();
	int as=0,cs=0,bs=0;
	for(int i=0;i<n;i++){
		as+=s[i]=='a';
		cs+=s[i]=='c';
		bs+=s[i]=='b';
	}

	if(cs < as && cs < bs){
		ll ans = 0;
		for(int i=0;i<n;i++){
			c>>=1;
			if(s[i] == 'a')a[i] = 1;
			else if(s[i] == 'b')c[i] = 1;
			else if(s[i] == 'c'){
				x = a & c;
				ans += x.count();
			}
		}
		cout << ans << '\n';
	}else if(as < cs && as < bs){
		ll ans = 0;
		for(int i=n-1;i>=0;i--){
			c<<=1;
			if(s[i] == 'c')a[i] = 1;
			else if(s[i] == 'b')c[i] = 1;
			else if(s[i] == 'a'){
				x = a & c;
				ans += x.count();
			}
		}
		cout << ans << '\n';
	}else{
		ll ans = 0;
		for(int i=0;i<n;i++)if(s[i] == 'c')c[nax-i-1] = 1;
		// cerr << c << '\n';
		for(int i=0;i<n;i++){
			if(s[i] == 'c')c[nax-i-1] = 0;
			else if(s[i] == 'a')a[nax-i-1] = 1;
			else if(s[i] == 'b'){
				x = (a >> (i+1)) & c;
				cerr << a << ' ' << c << ' ' << x << '\n';
				ans += x.count();
			}
		}
		cout << ans << '\n';
	}
}