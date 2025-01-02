#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int q , m ; cin >> q >> m ;
	vector<vector<int>> answer( q , vector<int>( 4 , -1 ) ) ;
	for( int i = 0 ; i < m ; i++ ){
		for( int j = 0 ; j < q ; j++ ){
			char a , r ; cin >> a >> r ;
			answer[j][(a-'A')] = ( ( r == 'T' ) ? 1 : 0 );
		}
	}
	vector< char > final(q);
	// for( auto i : answer ){
	// 	for( auto j : i ) cout << j << " ";
	// 	cout << '\n';
	// }
	for( int i = 0 ; i < q ; i++ ){
		bool flag = false ;
		int c = 0 , p = -1 ;
		for( int j = 0 ; j < 4 ; j++ ){
			if( answer[i][j] == 1 ){
				final[i] = ('A' + j );
				flag = true;
				break;
			}else if( answer[i][j] == 0 ){
				c++;
			}else{
				p = j ;
			}
		}
		if( flag ) continue;
		if( c == 3 ){
			// cerr << p << endl; 
			final[i] = ( 'A' + p );
		}
		else final[i] = '?';
	}
	for( int i = 0 ; i < final.size() ; i++ ){
		cout << final[i] ;
		if( i != final.size()-1 )cout << " ";
		else cout << '\n';
	}
}
int main(){
    fast
    int t ; cin >> t ;
    while( t-- )
    	solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/