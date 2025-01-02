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
    int n ; cin >> n ;
    vector< pair< ll , ll > > v(n);
    for( int i = 0 ; i < n ; i++ ) cin >> v[i].first >> v[i].second ;
    
    sort( all(v) );

	vector<ll> p ;
	pair< ll , ll > rn = v[0] ;
	for( int i = 1 ; i < n ; i++ ){
		if( v[i].first > rn.second || rn.first > v[i].second ){
			p.push_back(rn.first);
			rn = v[i] ;
			continue;
		}
		rn.first = max( rn.first , v[i].first ) ;
		rn.second = min( rn.second , v[i].second ) ;
	}
	p.push_back(rn.first);
	cout << p.size() << "\n";
	for( auto i : p ) cout << i << " ";
		cout << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/