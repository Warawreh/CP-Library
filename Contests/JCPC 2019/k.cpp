#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool solve(){
	int n ; cin >> n ;
	string a , b ; cin >> a >> b ;
	for( int i = 0 ; i < n ; i++ ){
		if( a[i] == b[i] ) continue ;
		// cout << i << endl;
		if( a[i] == '.' || b[i] == '.' ){
			if( a[i] == '.' ){
				if( (b[i] - '0')%2 ){
					if( i == n-1 ) return false;
					else if( b[i+1] == '.' ){
						swap( b[i] , b[i+1] );
						i--;
						continue;
					}
				}else return false;
			}else if( b[i] == '.' ){
				if( (a[i] - '0')%2 == 0 ){
					if( i == n-1 ) return false;
					else if( a[i+1] == '.' ){
						swap( a[i] , a[i+1] );
						i--;
						continue;
					}
				}else return false;
			}
		}else return false;
	}
	// cout << a << " " << b << endl;
	return true ;
}
int main(){
	fast
	int t ; cin >> t ;	
	while( t-- ){
		cout << ((solve())?"yes":"no") << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/