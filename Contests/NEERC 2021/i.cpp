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
	int s ; cin >> s ;
	for( int x = 0 ; x < 50 ; x++ ){
		for( int y = 0 ; y < 50 ; y++ ){
			int a = x * x + y * y ;
			if( a == s ){
				cout << 0 << " " << 0 << endl;
				cout << x << " " << y << endl;
				cout << x - y << " " << y + x << endl;
				cout << -y << " " << x << endl;
				return 0 ;
			}
		}
	}
	cout << "Impossible" << endl;
}
