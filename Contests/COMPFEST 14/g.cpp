#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll solve( ll n ){
	if( n <= 3 )
		return 2 * n + 1 ;
	else{
		n -= 4 ;
		ll z = n % 3 ;
		if( n % 3 == 2 ) z++;
		return 4 * ( n / 3 + 1 ) + 4 + z ;		
	}
}
int main(){
	fast
	int n ; cin >> n ;
	cout << solve( n ) << endl ;
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/