#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N = 1e6+10;
const int mod = 1e9+7;
#define all(x) (x).begin(), (x).end()

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
ll resp = 0 ;
ll n , m ;
vector< int > v;
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//Functions:-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
bool seg( int l , int r ){
    while( l < r ){
        if( v[l-1] != v[r-1] ) return false ;
        r--;
        l++;
    }
    return true;
}
bool check( int l , int r ){
    for( int i = l-1 ; i < r ; i++ ){
        int p = 1 ;
        bool flag = false ;
        while( i + p < r ){
            if( v[i] == v[i+p] )
                if( seg( i+1 , i+p+1 ) ){
                    flag = true ;
                    break;
                }
            p += 2;
        }
        if( !flag ) return false ;
        i = i+p ;
    }
    return true;
}
void gen( int i ){
    if( i == n ){
        int r = check( 1 , v.size() ) ;
        if( r ){
            for( auto i : v) cout << i << " ";
            cout << endl;
        }
        resp += r;
        return;
    }
    for( int j = 1 ; j <= m ; j++ ){
        v[i] = j ;
        gen( i + 1) ;
    }
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.precision(10);
cout << fixed;

    cin >> n >> m ;
    // for( int i = 2 ; i <= 16 ; i+= 2 ){
    //     n = i ;
    //     m = 4 ;
    // }
        resp = 0 ;
        v = vector<int>( n , 0 );
        gen(0);
        cout << resp << '\n';
    // v = { 2 , 2 , 1 , 1 };
}