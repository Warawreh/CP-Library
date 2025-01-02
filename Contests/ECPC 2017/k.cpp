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
	freopen("katryoshka.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ": ";
		int n,m,k;
		cin>>n>>m>>k;

		int x = min({n,m,k});
		n -= x;
		m -= x;
		k -= x;

		cout << x + min(n / 2 , k) << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/