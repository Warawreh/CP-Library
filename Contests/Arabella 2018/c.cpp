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

		ld dist = (a*c) / (b + c + c);
		dist = a - dist;
		ld ans = res({0,0} , {b+c , dist} , {b,a});

		ans += sqrt( a*a + b*b ) * x;

		ld nx = b * x;
		ld ny = a * x;

		b = b - nx;
		a = a - ny;

		dist = (a*c) * 1.0 / (b + c + c);
		dist = a - dist;
		ans += res({0,0} , {b+c , dist} , {b,a});

		printf("%.12Lf\n", ans);

	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/