#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map< string , int > m ;
map< string , int > u ;

bool srt( string x , string y ){
	if( m[x] != m[y] ){
		return ( m[x] > m[y] );
	}else return ( u[x] > u[y] );
}
int main(){
    fast
    int n , k ; cin >> n >> k ;
    vector<string> v ;
    string x;
    getline(cin, x);
    for( int i = 0 ; i < 3 * n ; i++ ){
    	string x ; getline(cin,x);
    	if( m[x] == 0 ){
    		v.push_back(x);
    	}
    	m[x]++ ;
		u[x] = i;
    }
    sort( all(v) , srt );
    for( auto i : v ){
    	k--;
    	cout << i << '\n';
    	if( k == 0 )break;
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/