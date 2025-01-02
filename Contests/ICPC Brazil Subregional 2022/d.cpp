#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int find( int n , int x ){
	int md = ( 1 << (n-1) );
	if( x == md ) return 0 ;
	if( md < x ) x = x - md ;
	return find( n , x*2 ) + 1 ;
}
int main(){
    fast
	ll n , x , y ; cin >> n >> x >> y ;
	int ansx = find( n , x ) ;
	int ansy = find( n , y ) ;
	cout << max(ansx , ansy) << endl;
}
