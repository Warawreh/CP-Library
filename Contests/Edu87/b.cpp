#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
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
		vector<int> a(3,1e9);
		int ans = 1e9;
		for(int i=0;i<s.size();i++){
			a[s[i] - '1'] = i;
			int cost = *max_element(all(a)) - *min_element(all(a)) + 1;
			ans = min(ans , cost);
		}
		if(ans > s.size())ans = 0;
		cout << ans << '\n';
	}
}