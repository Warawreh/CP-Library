#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N = 1e6+10;
const int mod = 1e9+7;
#define all(x) (x).begin(), (x).end()

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//Functions:-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void solve(){
    
    int n , m ; cin >> n >> m ;
    vector< string > mp(n) ;
    for( int i = 0 ; i < n ; i++ ) cin >> mp[i] ;

    vector< vector<int> > ti( n , vector<int>( m , 3000 ) ) ;
    
    queue< pair< int , int > > q ;
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < m ; j++ )
            if( mp[i][j] == 'G' ){
                ti[i][j] = 0 ;
                q.push( make_pair(i,j) );
            }

    int dr[] = { 0 , 0 , 1 , -1 };
    int dc[] = { 1 , -1 , 0 , 0 };
    char sy[] = { 'R' , 'L' , 'D' , 'U' };

    while( q.size() ){
        pair< int , int > nxp = q.front();
        q.pop();

        for( int i = 0 ; i < 4 ; i++ ){
            pair< int , int > nxpt = nxp;
            nxpt.first += dr[i] ;
            nxpt.second += dc[i] ;

            if( nxpt.first < 0 ) continue ;
            if( nxpt.second < 0 ) continue ;
            if( n <= nxpt.first ) continue ;
            if( m <= nxpt.second ) continue ;
            
            if( mp[nxpt.first][nxpt.second] == 'X' ) continue ;

            // Is it visited
            if( ti[nxpt.first][nxpt.second] <= ti[nxp.first][nxp.second] + 1 ) continue ;

            // update the nxp and the time
            ti[nxpt.first][nxpt.second] = ti[nxp.first][nxp.second] + 1 ;
            q.push( nxpt );
        }
    }

    pair< int , int > bp ;
    string path = "" ;
    vector<vector<int>> vis( n , vector<int>( m , 3000 ) );
    vector<vector<string>> vp( n , vector<string>( m , "" ) );

    queue< pair< int , int > > mv ;
    

    pair< int , int > sp ;

    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < m ; j++ )
            if( mp[i][j] == 'P' ){
                bp = make_pair(i,j);
                sp = bp ;
                vis[i][j] = 0 ;                
                mv.push( bp );
            }

    while( mv.size() ){

        pair< int , int > nxp = mv.front() ;
        string &npath = vp[nxp.first][nxp.second];
        mv.pop();

        if( ti[nxp.first][nxp.second] == ti[bp.first][bp.second] ){
            // same time as the best time
            if( nxp < bp ){
                // the new point is lexo cords
                bp = nxp ;
                path = npath ;
            }
        }else if( ti[nxp.first][nxp.second] > ti[bp.first][bp.second] ){
            // longer time to live
            bp = nxp ;
            path = npath ;
        }

        for( int i = 0 ; i < 4 ; i++ ){
            pair< int , int > nxpt = nxp;
            nxpt.first += dr[i] ;
            nxpt.second += dc[i] ;

            string cpath = npath + sy[i] ;

            if( nxpt.first < 0 ) continue ;
            if( nxpt.second < 0 ) continue ;
            if( n <= nxpt.first ) continue ;
            if( m <= nxpt.second ) continue ;
            if( mp[nxpt.first][nxpt.second] == 'X' ) continue ;

            if( vis[nxpt.first][nxpt.second] < vis[nxp.first][nxp.second] + 1 ) continue ;
                // i visited the point
            if( ti[nxpt.first][nxpt.second] <= vis[nxp.first][nxp.second] + 1 ) continue ;
                // i cannot travel because i will get caught
            
            if( vis[nxpt.first][nxpt.second] == vis[nxp.first][nxp.second] + 1 ){
                vp[nxpt.first][nxpt.second] = min(vp[nxpt.first][nxpt.second] , npath + sy[i]);
                continue;
            }
            vp[nxpt.first][nxpt.second] = npath + sy[i];
            vis[nxpt.first][nxpt.second] = vis[nxp.first][nxp.second] + 1 ;
            mv.push( nxpt );
        }
    }



    if( ti[bp.first][bp.second] == 3000 ){
        cout << "INFINITE ";
        if( path.size() ) cout << path ;
        else cout << "STAY";
        cout << endl;
    }else{
        cout << ti[bp.first][bp.second]-1 << " ";
        if( path.size() ) cout << path ;
        else cout << "STAY";
        cout << endl;
    }
    // cout << bp.first << " " << bp.second << endl;
    // cout << path << endl;
    // exit(0);    
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.precision(10);
cout << fixed;

#ifndef ONLINE_JUDGE
freopen("input.txt" , "r" , stdin );
#endif
    int t ; cin >> t ;
    for( int i = 1 ; i <= t ; i++ ){
        cout << "Case #" << i << ": ";
        solve();
    }
}