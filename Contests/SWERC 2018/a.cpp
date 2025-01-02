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
    int k ; cin >> k ;
    vector< int > s ;
    for( int i = 0 ; i < k ; i++ ){
        int x ; cin >> x ;
        s.push_back(x);
    }
    vector<bool> v( n , true );
    int ans = 0 ;
    for( auto i : s ){
        for( int j = i ; j <= n ; j += i ) v[j-1] = !v[j-1] ;
        int cans = 0 ;
        for( auto j : v ) cans += j ;
        cans = n - cans ;
        ans = max( ans , cans );
    }
    cout << ans << endl;
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/