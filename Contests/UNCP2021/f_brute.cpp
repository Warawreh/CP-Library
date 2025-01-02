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
  	int n , q ; cin >> n >> q ;
  	vector<string> v(n);
  	for( int i = 0 ; i < n ; i++ )
  		cin >> v[i] ;

  	while( q-- ){
  		int op ; cin >> op ;
  		if( op == 1 ){

  		}else{
  			int val ; cin >> val;

  			for( int i = n-1 ; 0 <= i ; i-- ){
				for( int j = n-1 ; 0 <= j ; j-- ){
  					
  					v[i][j] = v[i][j-1];
  				}  				
  			}
  		}
  	}
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/