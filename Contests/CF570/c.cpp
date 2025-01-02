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
		ll k,n,a,b;
		cin>>k>>n>>a>>b;
		if(n*b >= k)cout << -1 << '\n';
		else{
			cout << min(n,(k - b*n - 1) / (a - b)) << '\n';
		}
	}
}