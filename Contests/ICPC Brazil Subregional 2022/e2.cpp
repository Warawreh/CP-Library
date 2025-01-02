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
	vector<pair<int,int>> v(n);
	map< int , int > pos ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> v[i].first ;
		v[i].second = i+1 ;
	}
	sort( all(v) );
	for( int i = 0 ; i < n ; i++ ){
		if( pos[v[i].first] ) continue ;
		pos[v[i].first] = v[i].second ;
	}
	int ans = 1 ;
	for( int i = 0 ; i < n-1 ; i++ ){
		if( v[i].first + 1 == v[i+1].first ){
			if( v[i+1].second < v[i].second ) continue ;
			else ans++;
		}else ans++ ;
	}
	cout << ans << endl;
}