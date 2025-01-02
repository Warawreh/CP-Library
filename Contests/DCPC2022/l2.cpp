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


int main(){
    fast
  	int t;
  	cin>>t;
  	while(t--){
  		int n;
  		cin>>n;

  		vector<vector<int>> g(n,vector<int>(n));
  		// int at = 0;
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<n;j++)
        //         g[i][j] = ++at;
        // vector<int> x(n*n);
        // iota(all(x), 1);
        // vector<int> res;
        // int cnt = 0;
        // do{
        //     shuffle(all(x),rng);
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<n;j++)
        //             g[i][j] = x[i*n + j];
        //     }
        //     if(check(g)){
        //         if(res.empty())res = x;
        //         res = min(res , x);
        //         // break;
        //     }
        // }while(++cnt <= 1000000);
        // cerr << res.size() << '\n';

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         g[i][j] = res[i*n + j];
        // }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cerr << g[i][j] << ' ';
        //     cerr << '\n';
        // }
        // continue;
    
        int at=0;
  		for(int i=0;i<n+n-1;i++){

            if(i % 2 == 0){
      			int x = 0,y = i/2;
                cerr << x << ' ' << y << '\n';
      			while(x < n && y < n && x >= 0 && y >= 0){
      				g[x][y] = ++at;
      				x++;y--;
      			}
            }else{
                int x = n-1-i/2,y = n-1;
                cerr << x << ' ' << y << '\n';
                while(x < n && y < n && x >= 0 && y >= 0){
                    g[x][y] = ++at;
                    x++;y--;
                }
            }
  		}

        if(check(g) == 0){
            cout << n << '\n';
      		for(int i=0;i<n;i++){
      			for(int j=0;j<n;j++)
      				cout << g[i][j] << ' ';
      			cout << '\n';
      		}
             return 0;
        }
        // cerr << n << ' ' << "Done\n";

  	}  
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/