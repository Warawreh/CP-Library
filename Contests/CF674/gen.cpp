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
	int t = 1;
	cout << t << '\n';
	for(int i=0;i<t;i++){
		int x = uniform_int_distribution<int>(1, 1e9)(rng);
		cout << x << '\n';
	}
	// int n = uniform_int_distribution<int>(3, 12)(rng);
	// string s;
	// string tmp = "abc?";
	// for(int i=0;i<n;i++){
	// 	s += tmp[uniform_int_distribution<int>(0, 3)(rng)];
	// }
	// cout << n << '\n' << s << '\n';
}