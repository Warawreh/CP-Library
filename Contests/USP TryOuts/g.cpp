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
    int t ; cin >> t ;
    while( t-- ){
        string x , y = "" ; cin >> x ;
        int n = x.size();
        for( int i = 0 ; i < n ; i++ ){
            if( i != 0 )
                if( x[i-1] == x[i] ){ y += x[i]; continue; }
            if( i != n-1 )
                if( x[i+1] == x[i] ){ y += x[i]; continue; }
            y += x[i];
            y += x[i];
        }
        cout << y << '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/