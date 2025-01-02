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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<int> o;
		int len = 1;
		for(int i=1;i<s.size();i++){
			if(s[i] != s[i-1]){
				if(s[i-1] == '1')o.push_back(len);
				len = 0;
			}
			len++;
		}
		if(s.back() == '1')o.push_back(len);
		sort(all(o));
		reverse(all(o));
		int ans=0;
		for(int i=0;i<o.size();i+=2)ans += o[i];
		cout << ans << '\n';
	}
}