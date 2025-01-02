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
	freopen("task.in","r",stdin);	
	int t ; cin >> t ;
	while( t-- ){
		int n ; cin >> n ;
		set<ll> s;
		for( int i = 0 ; i < n ; i++ ){
			ll x ; cin >> x ;
			s.insert( x );
		}
		ll ca = 0 , cs = 0 , bans = n + 1 , pv = 0 ;
		for( auto i : s ){
			cs++;
			ca += i - pv - 1 ;
			// cout << n << " " << cs << " " << ca << " ";
			// cout << n - cs + ca << endl;
			bans = min( bans , n - cs + ca );
			pv = i ;
		}
		cout << bans << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/
