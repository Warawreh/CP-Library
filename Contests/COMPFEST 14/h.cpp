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
	int n ; cin >> n ;
	vector< int > v(n);
	int z = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> v[i] ;
		v[i] %= 3 ;
		z += ( v[i] == 0 ) ;
	}

	int b = n / 2 ;
	if( z * 2 >= n  ){
		cout << 2 << endl;		
		for( int i = 0 ; i < n ; i++ ){
			if( v[i] == 0 && b ){
				b-- ;
				cout << 1; 
				continue;
			}
			cout << 0;
		}
		cout << endl;
	}else{
		cout << 0 << endl;
		for( int i = 0 ; i < n ; i++ ){
			if( v[i] != 0 && b ){
				b-- ;
				cout << 1; 
				continue;
			}
			cout << 0;
		}
		cout << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/