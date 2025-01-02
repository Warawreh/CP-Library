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
    int ans = 1000000000;
    for( int i = 0 ; i < n ; i++ ){
        int a , b ; cin >> a >> b ;
        ans = min( ans , b/a );
    }
    cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/