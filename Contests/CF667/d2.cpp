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
		string n;
		int s;
		ll x;
		cin>>x>>s;
		n = to_string(x);
		int sum = 0;
		while(n.size() <= 18)n = "0" + n;
		for(char c : n)sum += c - '0';
		ll ans = 0;
		for(int i=18;i>=1;i--){
			if(sum <= s)break;

			bool g = 0;
			while(n[i] == '9'){
				sum -= 9;
				n[i] = '0';
				g = 1;
				i--;
			}
			if(g){
				sum++;
				n[i]++;
			}
			if(sum <= s)break;
			if(n[i] == 0)continue;
			sum -= (n[i] - '0');
			sum++;
			n[i-1]++;
			n[i] = '0';
		}
		for(char c : n){
			ans *= 10;
			ans += (c - '0');
		}
		// cerr << n << ' ' << ans << '\n';
		cout << ans - x << '\n';
	}	
}