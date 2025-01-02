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
	int tt;
	cin>>tt;
	while(tt--){
		string s;
		cin>>s;
		int n = s.size();
		vector<char> c;
		int ans = n;
		for(int i=0;i<n;i++){
			c.push_back(s[i]);
			while(c.size() >= 2 && c.back() == 'B'){
				c.pop_back();
				c.pop_back();
				ans-=2;
			}
		}
		cout << ans << '\n';
	}
}