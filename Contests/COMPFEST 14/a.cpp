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
	ll n , m ; cin >> n >> m ;
	if( m == 1 ) swap( n , m );
	cout << n * ( m - 1 ) << endl;
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/