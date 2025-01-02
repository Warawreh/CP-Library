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
	vector<pair<int,int>> v(3);
	vector<int> x(3) , y(3) ;
	for( ll i = 0 ; i < 3 ; i++ ){
		cin >> v[i].first >> v[i].second ;
		x[i] = v[i].first ;
		y[i] = v[i].second ;
	}
	sort( all( x ) ) ;
	sort( all( y ) ) ;
	cout << 4 << endl;
	cout << x[0] << " " << y[1] << " " << x[2] << " " << y[1] << endl;
	cout << v[0].first << " " << v[0].second << " " << v[0].first << " " << y[1] << endl;
	cout << v[1].first << " " << v[1].second << " " << v[1].first << " " << y[1] << endl;
	cout << v[2].first << " " << v[2].second << " " << v[2].first << " " << y[1] << endl;
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/