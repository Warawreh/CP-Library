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
	int n,m,t;
	cin>>n>>m>>t;
	int c = n;
	int lst = 0;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		n -= a - lst;;
		// cerr << n << '\n';
		if(n <= 0){
			cout << "No\n";
			return 0;
		}
		n += b-a;
		n = min(n , c);
		lst = b;
	}
	n -= t - lst;
	if(n <= 0)cout << "No\n";
	else cout << "Yes\n";
}