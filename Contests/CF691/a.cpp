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
	int n,m;
	cin>>n>>m;
	ll a=0,g2=0,lst = 0;
	for(int i=0;i<n;i++){
		ll b;
		cin>>b;
		if(i)g2 = gcd(g2 , b - lst);
		else a = b;
		lst = b;
	}
	// cerr << a << ' ' << g2 << '\n';
	for(int i=0;i<m;i++){
		ll x;
		cin>>x;
		cout << gcd(g2,a + x) << ' ';
	}
}