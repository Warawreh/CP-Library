#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ld solve(){
	ld n , r , k ; cin >> n >> r >> k ;
	ld angle = 2.0 * acos(-1) / k ;
	ld area1 = r * r * ( k * sin( angle ) / ( 2 * cos( angle / 2 ) * cos(angle / 2) ) - acos(-1) );
	ld val1 = 1.0 / ( cos( angle / 2 ) * cos(angle / 2) );
	ld val2 = 1 ;
	ld val3 = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		val3 += val2 ;
		val2 *= val1 ;
	}
	return val3 * area1	;
}
int main(){
	fast
	cout << setprecision(5) << fixed;
	freopen("glorious.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ": ";
		cout << solve() << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/