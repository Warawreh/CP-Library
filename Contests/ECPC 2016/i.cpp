#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	
struct point_2D {
	ll x , y ;
};
struct circle {
	point_2D cen ;
	ll r ;
};
ll S( ll x ){ return x * x ; }

int solve(){
	int n ; cin >> n ;
	ll R ; cin >> R ;
	
	vector<circle> circles(n);
	for( int i = 0 ; i < n ; i++ )
		cin >> circles[i].cen.x >> circles[i].cen.y >> circles[i].r ;

	map< ld , ll > add , remove ;
	set< ld > event ;
	for( auto c : circles ){
		if(abs(c.cen.y) > R - c.r)continue;
		ll a = S( R - c.r );
		ll b = S( c.cen.y );
		if( a < b ) continue ;

		ld res = sqrt( a - b );
		//res = fixin( res , 12 );
		ld x = c.cen.x ;
		event.insert( x - res );
		event.insert( x + res );
		// cout << x-res << " " << x+res << endl;
		add[ x - res ] += c.r ;
		remove[ x + res ] += c.r ;
	}
	ll mxans = 0 , sum = 0 ;
	for( auto i : event ){
		// cout << i << "\n";
		sum += add[i] ;
		mxans = max( mxans , sum );
		sum -= remove[i];
	}
	return mxans;
}
int main(){
   	fast
   	freopen("walk.in","r",stdin);
   	int t ; cin >> t ;
   	while( t-- ){
   		cout << solve() << '\n';
   	}
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/