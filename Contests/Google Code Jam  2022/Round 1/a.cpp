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
	string res;

	char x = s.back();
	for(int i=n-1;i>=0;i--){
		if(s[i] < x){
			res += s[i];
		}
		if(i && s[i] != s[i-1]){
			x = s[i];
		}
		res += s[i];
	}
	reverse(all(res));
	cout << res << '\n';
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