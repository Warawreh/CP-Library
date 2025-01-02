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
		int n;
		string s;
		cin>>n>>s;
		map<int,int> m;
		ll ans = 0;
		int sum = 0;
		m[0] = 1;
		for(int i=0;i<n;i++){
			sum += (s[i] - '0') - 1;
			ans += m[sum];
			m[sum]++;
		}
		cout << ans << '\n';
	}
}