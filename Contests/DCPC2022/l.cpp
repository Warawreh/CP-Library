#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool check( vector<vector<int>> &v ){
   for( int i = 0 ; i < v.size() ; i++ ){
      for( int a = 0 ; a < v[0].size() ; a++ ){
         for( int b = a+1 ; b < v[0].size() ; b++ ){
            for( int c = b+1 ; c < v[0].size() ; c++ ){
               if( v[i][a] - v[i][b] == v[i][b] - v[i][c] ){
                    cerr << "R " << i << ' ' << a << ' ' << b << ' ' << c << '\n';
                    return false ;
               }
               if( v[a][i] - v[b][i] == v[b][i] - v[c][i] ){
                    cerr << "C "<< i << ' ' << a << ' ' << b << ' ' << c << '\n';
                return false ;
               }
            }
         }
      }
   }
   return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> type(n*n+1,0);
    vector<vector<int>> g;
    for(int i=0;i<n;i++){
        int at = 1;
        vector<int> row;
        for(int j=0;j<n;j++){
            while(at < n * n && type[at] != 0)at++;
            int cur = at;
            type[cur] = 1;

            for(int &x : row){
                int to = cur + (cur - x);
                if(to > 0 && to <= n*n && type[to] == 0)type[to] = 2;
                else break;
            }
            cout << cur << ' ';
            row.push_back(cur);
        }
        cout << '\n';
        g.push_back(row);
        for(int j=1;j<=n*n;j++)
            if(type[j] == 2)
                type[j] = 0;
    }

}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}
