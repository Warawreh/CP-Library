#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void print( vector<int> &a ){
	for( auto i : a ) cout << i << " " ;
		cout << endl;
}
void o( vector<int> &a , vector<int> &b , vector<int> &c ){
	for( int i = 0 ; i < a.size() ; i++ ) c[i] = b[a[i]-1];
	print( c );	
}
void inv( vector<int> &a , vector<int> &b ){
	for( int i = 0 ; i < a.size() ; i++ ) b[a[i]-1] = i+1;
	print( b );	
}
int main(){
    fast
    int n ; cin >> n ;
    vector< int > p(n) , f(n) , np(n) , g(n) , nf(n) , ng(n) , temp(n) ;
    for( int i = 0 ; i < n ; i++ ) cin >> p[i] ;
    for( int i = 0 ; i < n ; i++ ) cin >> f[i] ;
	inv( p , np ) ;
	inv( f , nf ) ;
	o( np , f , temp );
	o( temp , p , g );
	inv( g , ng );
	o( np , nf , temp );
	o( temp , p , ng );
	
}
