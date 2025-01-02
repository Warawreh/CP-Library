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
	freopen("mosalah.in","r",stdin);	
	int t;
	cin>>t;
	while(t--){
		ll n,m,x,y;
		cin>>n>>m>>x>>y;

		if(y == 0){
			if(m < n * x)cout << -1 << '\n';
			else cout << 0 << '\n';
		}else{
			cout << max(0LL , (n * (x + y)) - m) << '\n';
		}
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/