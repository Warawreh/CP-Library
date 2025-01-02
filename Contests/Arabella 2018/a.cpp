#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string cha( char a , int d ){
	string ans = "" ;
	ans += a;
	while( d-- )
		ans += '0';
	return ans ;
}
void solve(){
	string a , b ; cin >> a >> b ;

	int neg = 0;
	if(a[0] == '-'){
		neg++;
		a = a.substr(1);
	}

	if(b[0] == '-'){
		neg++;
		b = b.substr(1);
	}
	neg%=2;

	vector<pair<string,string>> v;
	for( int i = 0 ; i < a.size() ; i++ ){
		for( int j = 0 ; j < b.size() ; j++ ){
			if( a[i] == '0' || b[j] == '0' )
				continue;
			v.push_back({cha(a[i],a.size()-i-1),cha(b[j],b.size()-j-1)});
		}
	}

	if(neg)cout << "-";
	for( int i = 0 ; i < v.size() ; i++ ){
		cout << v[i].first << " x " << v[i].second << " ";
		if( i != v.size()-1 ){
			if(neg)cout << "- ";
			else cout <<"+ ";
		}
	}
	cout << endl;
	return;
}
int main(){
	fast
	int t ; cin >> t ;
	while( t-- ){
		solve( );
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/