#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double PI = acos(-1);

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n*=2;
		double deg = PI/n;
		double ans = cos(deg/2) / sin(deg);
		// cerr << 1/sin(deg) << ' ' << ans << '\n';
		cout << setprecision(12) << fixed << ans << '\n';
	}
}