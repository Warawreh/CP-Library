#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n ; cin >> n ;
	vector< pair<int,int> > door( 22 ) ;
	vector< pair<pair<int,int>,int> > reg( 22 ) ;
	for( int i = 0 ; i < n ; i++ ){
		char c ; cin >> c ;
		if( c == 'C' ){
			int r , x , y ; cin >> r >> x >> y ;
			door[r] = ({y,x});
		}else{
			int r1 , r2 , at ; cin >> r1 >> r2 >> at ;
			reg.push_back({{r1,r2},at});
		}
	}
	
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/