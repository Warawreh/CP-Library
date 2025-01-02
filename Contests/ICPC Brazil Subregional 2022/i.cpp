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
	vector<int> v(8);
	bool flag = false ;
	for( int i = 0 ; i < 8 ; i++ ){
		cin >> v[i] ;
		if( v[i] == 9 ) flag = true ;
	}
	cout << (( flag ) ? "F" : "S" ) << endl;
}
