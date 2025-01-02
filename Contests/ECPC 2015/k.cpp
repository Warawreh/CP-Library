#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p;

ll find( ull a , ull b , int n ){
    ll ans= 0;

    vector<ll> hv = vector<ll>(p,0);
    // hv[0] = 1;
    
    for( int i = 0 ; i < n ; i++ ){
        a *= 10 ;
        ull x = a/b;
        x %= p;
        a = a%b ; 
        vector<ll> nxt(p);
        for(int j=0;j<p;j++){
            nxt[(j * 10 + x)%p] += hv[j];
        }
        nxt[x]++;
        hv = nxt;
        ans += hv[0];
    }
    return ans;
}
void solve(){
    ull a , b ;
    cin >> a >> b ;
    int n ;
    cin >> n >> p ;
    
    cout << find( a , b , n ) << '\n';
    
}
int main(){
    fast
    int t ; cin >> t ;
    while( t-- )solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/