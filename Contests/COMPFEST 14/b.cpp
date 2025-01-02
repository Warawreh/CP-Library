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
	int n , pwr ; cin >> n >> pwr ;
	pwr++;
	vector< int > v(n);
	for( int i = 0 ; i < n ; i++ ) cin >> v[i] ;
	sort( all( v ) );
	
	int l = 0 , r = n ;
	ll ans = 0 ;
	while( l < r ){
		int needed_players = ( pwr + v[r-1] - 1 ) / v[r-1] ;
		if( l + needed_players - 1 < r ){
			r--;
			l += needed_players - 1 ; 
			ans++;
			continue;
		}else{
			break;
		}
		cout << needed_players << endl;
		exit( 0 );
	}
	cout << ans << endl;
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/