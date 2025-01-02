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
    ld d , v1 , v2 , v3 , t ; cin >> d >> v1 >> v2 >> v3 >> t ;

    ld tb = 0 , pb = 0 , pe = 1 ;
    int c = 0 ;
    // d ,,,,,,
    while( true ){
    	ld vd = ( ( c % 2 == 0 ) ? v3 : -v3 );
    	ld vmv = ( ( c % 2 == 0 ) ? v2 : v1 );
    	if( d <= tb * v2 && c == 0 ) vmv = 0 ; 
    	c = 1 - c ;
    	ld tt = ( pe - pb ) / ( vd - vmv ) ;

    	if( d <= (tb+tt)*v2 )
    		tt = d/v2 - tb ;
    	if( tb <= t && t <= tt ){
    		// found it 
    		break ;
    	}
    	
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/