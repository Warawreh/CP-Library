#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> v;
bool findxy( int r , int c , int &x , int &y ){
    int tx = 0 ;
    int tr = r , tc = c ;
    while( true ){
        if( tr == v.size() )break;
        if( tc == v[0].size() )break;
        if( v[tr][tc] == '#' ){
            tx++;
            tr++;
            tc++;
        }else break ;
    }

    int tot = 0 ; tr = r , tc = c ;
    while( true ){
        if( tr == v.size() )break;
        if( tc == v[0].size() )break;
        if( v[tr][tc] == '#' ){
            tot++;
            tr++;
        }else break ;
    }

    int ty = tot - 2 * tx ;
    if( ty <= 0 ) return false ;
    x = tx ;
    y = ty ;
    return true ;
}
bool shape( int r , int c , int x , int y , char &res ){
    bool l1 = true , l2 = true , s1 = true , s2 = true , s3 = true ;

    for( int mc = 0 ; mc < x+1 ; mc++ ){
        int stc = c ; int cc = stc + mc ;
        char tc = '.';
        if( mc ) tc = '#';

        for( int mr = 0 ; mr < 3*x+2*y+2 ; mr++ ){
            int str = r ; int rr = str + mr ;
            // cout << v[rr][cc] ;
            if( mr == 0 || mr == 3*x+2*y+1 ){
                if( v[rr][cc] != '.' ){ l1 = false; break; }
            }else{
                if( v[rr][cc] != tc ){ l1 = false ; break; }
            }
        }
        // cout << endl;
    }
    for( int mc = 0 ; mc < x+1 ; mc++ ){
        int stc = c+2*x+y+1 ; int cc = stc - mc ;
        char tc = '.';
        if( mc ) tc = '#';

        for( int mr = 0 ; mr < 3*x+2*y+2 ; mr++ ){
            int str = r ; int rr = str + mr ;
            // cout << v[rr][cc] ;
            if( mr == 0 || mr == 3*x+2*y+1 ){
                if( v[rr][cc] != '.' ){ l2 = false; break; }
            }else{
                if( v[rr][cc] != tc ){ l2 = false ; break; }
            }
        }
        // cout << endl;
    }
    for( int mr = 0 ; mr < x+1 ; mr++ ){
        int str = r ; int rr = str + mr ;
        char tc = '.';
        if( mr ) tc = '#';

        for( int mc = 0 ; mc < 2*x+y+2 ; mc++ ){
            int stc = c ; int cc = stc + mc ;
            // cout << v[rr][cc] ;
            if( mc == 0 || mc == 2*x+y+1 ){
                if( v[rr][cc] != '.' ){ s1 = false; break; }
            }else{
                if( v[rr][cc] != tc ){ s1 = false ; break; }
            }
        }
        // cout << endl;
    }
    for( int mr = 0 ; mr < x+1 ; mr++ ){
        int str = r + 3*x+2*y+1 ; int rr = str - mr ;
        char tc = '.';
        if( mr ) tc = '#';

        for( int mc = 0 ; mc < 2*x+y+2 ; mc++ ){
            int stc = c ; int cc = stc + mc ;
            // cout << v[rr][cc] ;
            if( mc == 0 || mc == 2*x+y+1 ){
                if( v[rr][cc] != '.' ){ s3 = false; break; }
            }else{
                if( v[rr][cc] != tc ){ s3 = false ; break; }
            }
        }
        // cout << endl;
    }
    for( int mr = 1 ; mr < x+1 ; mr++ ){
        int str = r+x+y ; int rr = str + mr ;
        char tc = '.';
        if( mr ) tc = '#';
        for( int mc = 0 ; mc < 2*x+y+2 ; mc++ ){
            int stc = c ; int cc = stc + mc ;
            // cout << v[rr][cc] ;
            if( mc == 0 || mc == 2*x+y+1 ){
                if( v[rr][cc] != '.' ){ s2 = false; break; }
            }else{
                if( v[rr][cc] != tc ){ s2 = false ; break; }
            }
        }
        // cout << endl;
    }
    if( l1 & l2 & s1 & s2 & !s3 ){ res = 'a' ; return true ; }
    if( l1 & l2 & s1 & s2 & s3 ){ res = 'b' ; return true ; }
    if( l1 & !l2 & s1 & !s2 & s3 ){ res = 'c' ; return true ; }
    return false ;
}

int main(){
    fast
    int n , m ; cin >> n >> m ;
    v.clear();
    v.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> v[i] ;

    char s ;
    int x , y ;
    bool res = findxy( 1 , 1 , x , y );
    if( res ){
        res = shape( 0 , 0 , 1 , 1 , s ) ;
        if( res ) cout << s << endl;
        else cout << "no" << endl;
    }else cout << "no2" << endl;
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/