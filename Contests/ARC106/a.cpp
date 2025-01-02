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
	ll n;
	cin>>n;
	ll a = 5;
	int x=1;
	while(a < n){
		ll cur = n - a;
		int y = 0;
		while(cur % 3 == 0){
			cur /= 3;
			y++;
		}
		if(cur == 1 && y){
			cout << y << ' ' << x << '\n';
			return 0;
		}
		a*=5;
		x++;
	}
	cout << -1 << '\n';
}