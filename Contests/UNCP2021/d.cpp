#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string equ ;
int p = 0 ;
int conv( string num ){
	int ans = 0 ;
	for( int i = 0 ; i < num.size() ; i++ ){
		ans = ans * 10 + (num[i]-'0') ;
	}
	return ans ;
}
int get_number(){
	string num = "" ;
	while( 0 <= (equ[p] - '0') && (equ[p] - '0') <= 9 ){
		num += equ[p];
		p++;
		if( p == equ.size() )break;
	}
	return conv( num );
}
pair< int , int > enter_term(){
	pair< int , int > res ;
	bool pos = true ;
	if( equ[p] == '-' ){ pos = false ; p++ ; }
	else if( equ[p] == '+' ){ p++ ; }

	int cof = get_number();
	if( cof == 0 ) cof = 1 ;
	res.second = cof * (( pos ) ? 1 : -1 );
	if( equ[p] == 'x' ){
		p++;
		if( equ[p] == '^' ){
			p++;
			pos = true ;
			if( equ[p] == '-' ){ pos = false ; p++ ; }
			int exp = get_number();  
			res.first = exp * (( pos ) ? 1 : -1 );
		}else{
			res.first = 1 ;
		}
	}
	return res ;
}
vector<pair<int,int>> enter_poly(){
	vector<pair<int,int>> terms ;
	while( p != equ.size() )
		terms.push_back( enter_term() );
	sort( all(terms) );
	vector<pair<int,int>> fix;
	for( auto i : terms ){
		if( fix.size() ){
			if( fix.back().first == i.first ) fix.back().second += i.second ;
			else fix.push_back(i);
		}else fix.push_back(i);
	}
	return fix ;
}
vector<pair<int,int>> diff( vector<pair<int,int>> &p ){
	vector<pair<int,int>> res ;
	for( auto i : p ){
		if( i.first == 0 || i.second == 0 ) continue ;
		else res.push_back( { i.first - 1 , i.second * i.first } );
	}
	return res;
}
int main(){
    fast
    cin >> equ ;
    vector<pair<int,int>> poly = enter_poly();
    vector<pair<int,int>> fans = diff( poly );
    if( fans.size() == 0 ){
    	cout << 0 << endl;
    	return 0;
    }
    for( int i = 0 ; i < fans.size() ; i++ ){
    	int cof = fans[i].second ;
    	int exp = fans[i].first ;
    	// cof x ^ exp
    	if( exp ){
    		// cof x ^ exp
    		if( cof > 0 ){
    			if( i != 0 ) cout << '+' ;
    			if( abs(cof) != 1 ) cout << cof ;
    		}else{
    			cout << '-' ;
    			if( abs(cof) != 1 ) cout << abs(cof) ;
    		}
    		cout << 'x';
    		if( exp != 1 ) cout << '^' << exp ;
    	}else{
    		// cof
    		if( cof > 0 && i != 0 ) cout << '+' ;
    		cout << cof ;
    	}
    }
    cout << endl;
}

/*
22 -23
2 0
-1 1
10 4
*/

//4x-23+1+3-2-5x+10x^4-10x^-23+23+32x^-23
