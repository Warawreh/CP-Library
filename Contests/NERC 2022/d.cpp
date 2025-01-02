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
		string x , y ; cin >> x >> y ;
		vector<vector<int>> v(26,vector<int>(1,0));
		for( int i = 0 ; i < x.size() ; i++ ){
			v[x[i]-'A'][0]++;
			v[x[i]-'A'].push_back(i+1);
		}
		reverse( all( y ) );
		bool flag = true ;
		int p = x.size() + 1 ;
		for( int i = 0 ; i < y.size() ; i++ ){
			if( v[ y[i] - 'A' ][0] == 0 ){
				flag = false ;
				break;
			}
			int val = v[ y[i] - 'A' ][v[ y[i] - 'A' ][0]] ;
			if( val > p ){
				flag = false ;
				break ;
			}
			p = val ;
			v[ y[i] - 'A' ][0]--;
		}
		cout << ( ( flag ) ? "YES" : "NO" ) << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/