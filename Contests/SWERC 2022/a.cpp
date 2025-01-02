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
		int n ; cin >> n ;
		int p[10];
		for( int i = 0 ; i < 10 ; i++ )
			p[i] = 0 ;
		for( int i = 0 ; i < n ; i++ ){
			int x , y ; cin >> x >> y ;
			p[y-1] = max( p[y-1] , x );
		}
		bool flag = true ;
		int sum = 0 ;
		for( int i = 0 ; i < 10 ; i++ ){
			if( p[i] == 0 )
				flag = false;
			sum += p[i];
		}
		if( flag )
			cout << sum << endl;
		else
			cout <<  "MOREPROBLEMS" << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/