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
		int n,m;
		cin>>n>>m;
		ll v = 0;
		for(int i=1;i<=n;i++){
			ll x;
			cin>>x;
			v += x;
		}
		cout << (v == m ? "YES\n" : "NO\n");
	}
}