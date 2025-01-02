#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
   int n ; cin >> n ;
   vector< vector<int> > edges( n+1 , vector<int>() );
   for( int i = 1 ; i <= n ; i++ ){
      int x ; cin >> x ;
      if( i - x > 0 ) edges[i - x].push_back( i ) ;
      if( i + x <= n )edges[i + x].push_back(i ) ;
   }
   vector<int> ans( n+1 , -1 );
   queue<int> q ;
   q.push( n ) ;
   ans[n] = 0 ;
   while( q.size() ){
      int nn = q.front();
      q.pop();
      for( auto i : edges[nn] ){
         if( ans[i] != -1 ) continue ;
         q.push(i);
         ans[i] = ans[nn] + 1 ;
      }
   }
   for( int i = 1 ; i <= n ; i++ )
      cout << ans[i] << '\n';
}
int main(){
   fast
   freopen("jumping.in","r",stdin);
   int t ; cin >> t ;
   while( t-- ) solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/