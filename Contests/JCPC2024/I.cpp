#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int mod = 1e9 + 7;


vector<ll> layer;

ll layerNum( ll x ){
    auto p = lower_bound( layer.begin() , layer.end() , x );
    return (p-layer.begin());
}

ll is_cor( ll x ){
    ll l = layerNum( x );
    if( l == 0 ) return 0;
    return ( x - layer[l-1] - 1 ) % l;
}

ll solve( ll x ){
    if( x == 1 ) return 1;

    ll l = layerNum( x );
    ll p = is_cor( x );

    vector< ll > la(1,1);
    ll c = 1;

    while( c <= l ){
        vector<ll> lb( c , 0 );
        for( ll i = 0 ; i < c ; i ++ ){
            if( i == 0 ) lb[i] = la[i];
            else{
                lb[i] = ((la[i-1])%mod + (la[i%(c-1)])%mod)%mod ;
            }
        }

        // for( auto i : la ) cout << i << " ";
        // cout << endl;

        ll sum = 0;
        for( auto i : lb ) sum = (sum%mod + i)%mod;
        
        sum = (sum * 12)%mod;    

        for( ll i = 0 ; i < c ; i++ ){
            lb[i] = (sum - lb[i] + mod)%mod;
        }

        // for( auto i : lb ) cout << i << " ";
        // cout << endl;

        la = lb;
        c++;
    }
    // cout << p << endl;
    // for( auto i : la ) cout << i << " ";
    //     cout << endl;


    return la[p];
}
int main(){
    fast

    layer.push_back(1);
    int l = 1;
    while( layer.back() <= 1e5 ){
        layer.push_back( layer.back() + 6 * l++ );
    }

    int n;
    cin >> n ;
    cout << solve( n ) << endl;
}
