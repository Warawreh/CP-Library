#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll number_of_digits( ll x ){
	ll d = 1 ;
	ll base = 10 ;
	while( x / base ){
		base *= 10 ;
		d++;
	}
	return d ;
}
ll join( pair< pair< ll , ll > , pair< ll , ll > > x ){
	ll shift = 1 ;
	for( int i = 0 ; i < x.first.second ; i++ )
		shift *= 10;
	return x.first.first + x.second.first * shift ;
}
pair< pair< ll , ll > , pair< ll , ll > > split( ll x ){
	ll y = number_of_digits( x );
	ll shift = 1 ;
	for( int i = 0 ; i < ( y + 1 ) / 2 ; i++ )
		shift *= 10;
	return { { x % shift , ( y + 1 ) / 2 } , { x / shift , y / 2 } };
}
ll refr( pair< ll , ll > x ){
	ll nx = 0 ;
	ll shift = 9 ;
	for( int i = 0 ; i < x.second ; i++ ){
		nx += shift;
		shift *= 10 ;
	}
	return nx ;
}
ll find( pair< pair< ll , ll > , pair< ll , ll > > x ){

	if( x.second.first == 1 ){
		return refr( x.first ) ;
	}
	ll sf = x.second.first ;
	ll ff = x.first.first ;
	ll ans = 0 ;
	for( int i = 2 ; i * i <= sf ; i++ ){
		if( sf % i == 0 ){		
			if( ff / i ){
				ans = max( ans , i * ( ff / i ) );
			}
		}
	}

	if( ff / sf ){
		ans = max( ans , sf * ( ff / sf ) );
	}
	if( ans )
		return join( { { ans , x.first.second } , { sf , x.second.second } } );
	else
		return find( { { refr( x.first ) , x.first.second } , { sf - 1 , x.second.second } } );
}
void solve(){
	ll l , r ; cin >> l >> r ;
	ll res = find( split( r ) );
	if ( l <= res ) cout << res << endl;
	else cout << "impossible" << endl;
}
int main(){
	fast
	freopen("halfnice.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ": ";
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/