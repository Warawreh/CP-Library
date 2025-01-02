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
   freopen("popcorn.in","r",stdin);
   int t ; cin >> t ;
   ll fact[22];
   fact[0] = 1 ;
   for( int i = 1 ; i <= 20 ; i++ )
   	fact[i] = fact[i-1] * i ;
	while( t-- ){
		ll a , b ; cin >> a >> b ;
		ll ans = fact[a] / fact[a-b];
		ans = ans / fact[b];
		cout << ans << endl;
   }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/