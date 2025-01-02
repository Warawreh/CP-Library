#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool solve(){
	string x ; cin >> x ;
	sort( all(x) );
	return ( x == "ABCDEFGHIJKLM" );
}
int main(){
	fast
	int t ; cin >> t ;
	while( t-- ){
		if( solve() )cout << "YES\n";
		else cout << "NO\n";
	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/