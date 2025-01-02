#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int find( int a , int b ){
	int ans = 0 ;
	while( a || b ){
		if( (a&1) ^ (b&1) ) ans++;
		a = ( a >> 1 );
		b = ( b >> 1 );
	}
	return ans;
}
int solve(){
	int n ; cin >> n ;
	vector<int> v(n);
	for( int i = 0 ; i < n ; i++ ) cin >> v[i];
	int ans = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		for( int j = i+1 ; j < n ; j++ ){
			ans = max( ans , find( v[i] , v[j] ) );
		}
	}
	return ans;
}
int main(){
	fast
	int t ; cin >> t ;
	while( t-- )
		cout << solve() << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/