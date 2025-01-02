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
	ll a , x ; cin >> a >> x ;
	ll b , y ; cin >> b >> y ;
	ll t ; cin >> t ;
	ll csd1 = a + max( ll(0) , t - 30 ) * x * ll(21) ;
	ll csd2 = b + max( ll(0) , t - 45 ) * y * ll(21) ;
	cout << csd1 << " " << csd2 << endl;
}
