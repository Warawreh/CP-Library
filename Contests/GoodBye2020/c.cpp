#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;

void change(int i){
	vector<bool> l(26);
	for(int j=i-2;j<=i+2;j++){
		if(j >= 0 && j < s.size()){
			l[s[j] - 'a'] = 1;
		}
	}
	for(int j=0;j<26;j++){
		if(!l[j])s[i] = char('a' + j);
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int n = s.size();
		int ans = 0;
		for(int i=0;i<n-2;i++){
			if(s[i] == s[i+1]){
				ans++;
				change(i+1);
			}
			if(s[i] == s[i+2]){
				ans++;
				change(i+2);
			}
		}
		if(s[s.size() - 1] == s[s.size() - 2])ans++;
		cout << ans << '\n';
	}
}