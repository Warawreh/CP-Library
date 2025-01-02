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
	int n;
	string s;
	cin>>n>>s;
	int ans = 0;
	for(int i=0;i<n;i+=2){
		int c1 = (s[i] == 'a') + (s[i+1] == 'b');
		int c2 = (s[i] == 'b') + (s[i+1] == 'a');
		if(c1 < c2){
			ans += c1;
			s[i] = 'b';
			s[i+1] = 'a';
		}else{
			ans += c2;
			s[i] = 'a';
			s[i+1] = 'b';
		}
	}
	cout << ans << '\n' << s << '\n';
}