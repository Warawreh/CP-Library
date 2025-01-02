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
	int t ; cin >> t ;
	while( t-- ){
		int n , m , k ; cin >> n >> m >> k ;

		vector<char> v(n);
		for( int i = 0 ; i < n ; i++ )
			cin >> v[i] ;
		int ans = 0 ;
		for( int j = 0 ; j < m ; j++ ){
			char resp ; cin >> resp ;
			if( resp == 'A' )k = n ;
			else{
				int np ; cin >> np ;
				if( np > k )
					k = np;
				else if( v[np-1] == 'S' )
					ans++;
			}
		}
		cout << ans << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/