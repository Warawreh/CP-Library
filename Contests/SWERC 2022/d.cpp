#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string red ( string x ){
	string ans = "" ;
	int flag = 0;
	for( int i = 0 ; i < x.size() ; i++ ){
		if( x[i] == 'B' )
			flag++;
		else
			ans += x[i];
	}
	for( int i = 0 ; i < (int)ans.size() ; i++ ){
		i = max( 0 , i );
		// cerr << ans << " " << i << " " << ans[i] << endl;
		if( (i + 1) < ans.size() ){
			if( ans[i] == ans[i+1] ){
				ans = ans.substr( 0 , i ) + ans.substr(i+2,ans.size());
				i-=2;
				continue;
			}
		}
	}
	if( flag % 2 )
		ans += 'B';

	return ans ;
}
int main(){
	fast
	int t ; cin >> t ;
	while( t-- ){
		string x , y ; cin >> x >> y ;
		x = red( x );
		y = red( y );
		cout << (( x == y )? "YES" : "NO") << endl;
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/