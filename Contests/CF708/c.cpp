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
	int n=2,k;
	while(t--){
		n++;
		// cin>>n>>k;
		k = 3;
		int x = n/3;
		cout << x << ' ' << x << ' ' << n - 2*x << '\n';
		if(((x*(n-2*x))/gcd(x,n-2*x) * 2 > n)){
			cout << n << '\n';
		}
	}
}