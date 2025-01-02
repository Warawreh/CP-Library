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
		int n = s.size();
		int a=0,b=0;
		for(int i=0;i<n;i++){
			a += s[i] == '0';
		}
		int ans = min(a , n-a);
		for(int i=0;i<n;i++){
			a -= s[i] == '0';
			b += s[i] == '0';
			ans = min(ans , min(a + i + 1 - b , n - i - 1 - a + b));
		}
		cout << ans << '\n';
	}
}