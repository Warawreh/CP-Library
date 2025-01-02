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

    	vector<int> v,v2;
    	{
	    	deque<int> q;
	    	for(int i=n-1;i>=0;i--){
	    		if(i % 2)q.push_back(i);
	    		else q.push_front(i);
	    	}

	    	while(q.size()){
	    		v.push_back(q.front());
	    		q.pop_front();
	    	}
    	}

    	{
    		deque<int> q;
	    	for(int i=0;i<n;i++){
	    		if(i % 2)q.push_back(i);
	    		else q.push_front(i);
	    	}

	    	while(q.size()){
	    		v2.push_back(q.front());
	    		q.pop_front();
	    	}
    	}

    	vector<vector<int>> g(n,vector<int>(n));
  		int at = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j] = ++at;

        vector<vector<int>> g2(n);
        for(int i=0;i<n;i++){
        	g2[i] = g[v[i]];
        }
        g = g2;

        for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout << g[i][j] << ' ';
			cout << '\n';
		}
		


        for(int j=0;j<n;j++){
        	for(int i=0;i<n;i++){
        		g2[i][j] = g[i][v2[j]];
        	}
        }
        g = g2;

        if(check(g) == 0){
            cout << n << '\n';
      		for(int i=0;i<n;i++){
      			for(int j=0;j<n;j++)
      				cout << g[i][j] << ' ';
      			cout << '\n';
      		}
             return 0;
        }
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/