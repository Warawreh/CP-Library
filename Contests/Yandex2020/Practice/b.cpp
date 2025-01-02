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
	string s;
	cin>>s;
	int n = s.size();
	string ans = "zzzz";
	for(int i=0;i<n;i++){
		if(i + 1 < n && s[i] == s[i+1]){
			if(ans.size() > 2 || ans[0] > s[i])ans = string(2,s[i]);
		}
		if(i + 2 < n && s[i] == s[i+2]){
			ans = min(ans,s.substr(i,3));
		}
	}
	if(ans == "zzzz")ans = "-1";
	cout << ans << '\n';
}