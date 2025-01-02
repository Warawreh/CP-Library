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
	vector<pair<int,int>> v( 13 );
	for( int i = 1 ; i <= 13 ; i++ ) v[i-1] = { i , 4 } ;
	int suma = 0 , sumb = 0 ;
	for( int i = 0 ; i < 2 ; i++ ){
		int x ; cin >> x ;
		v[x-1].second--;
		if( 10 <= x ) suma += 10 ;
		else suma += x ;
	}
	for( int i = 0 ; i < 2 ; i++ ){
		int x ; cin >> x ;
		v[x-1].second--;
		if( 10 <= x ) sumb += 10 ;
		else sumb += x ;
	}
	for( int i = 0 ; i < n ; i++ ){
		int x ; cin >> x ;
		v[x-1].second--;
		int val = 0 ;
		if( 10 <= x ) val += 10 ;
		else val += x ;
		suma += val ;
		sumb += val ;
	}
	for( int i = 1 ; i <= 13 ; i++ ){
		int val = 0 ;
		if( 10 <= i ) val = 10 ;
		else val = i ;
		if( v[i-1].second == 0 ) continue ;
		if( 23 < suma + val && sumb + val <= 23 ){
			cout << i << endl;
			return 0 ;
		}
		if( sumb + val == 23 ){
			cout << i << endl;
			return 0 ;
		}		
	}
	cout << -1 << endl;
}
