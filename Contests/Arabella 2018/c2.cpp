#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ld S(ld a){return a*a;}

inline ld des( pair<ld,ld> x , pair<ld,ld> y ){
	return sqrt( S(x.first-y.first)+S(x.second-y.second) );
}
inline ld res( pair<ld,ld> x , pair<ld,ld> y , pair<ld,ld> z ){
	return des( x , y ) + des( y , z );
}

inline ld tern( ld l , ld r , pair<ld,ld> s , pair<ld,ld> d , ld post ){
	ld result = 1e18;
	for(int i=0;i<50;i++){
		ld mid1 = l + ( r - l ) / 3.0 ;
		ld mid2 = r - ( r - l ) / 3.0 ;
		ld val1 = res( s , {post,mid1} , d );
		ld val2 = res( s , {post,mid2} , d );

		result = min({result , val1 , val2});

		if( val1 < val2 ){
			r = mid2;
		}else{
			l = mid1;
		}
	}
	// cerr << l << ' ' << r << '\n';

	return result;
}
int main(){
	int t ;
	scanf("%d",&t);
	while( t-- ){
		vector<int> v(4);
		for(int i=0;i<4;i++)scanf("%d",&v[i]);
		ld a , b , c ;
		ld x;
		a = v[0];b = v[1];c = v[2]; x = v[3];
		x /= 100.0;
		ld ans = tern( 0 , a , {0,0} , {b,a} , b+c );
		// cout << ans << endl;

		ans += sqrt( a*a + b*b ) * x;
		// cout << ans << endl;

		ld nx = b * x;
		ld ny = a * x;
		// cout << nx << " " <<  ny << endl;
		ans += tern( 0 , a , {b,a} , {nx,ny} , b+c );

		printf("%.12Lf\n", ans);
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/