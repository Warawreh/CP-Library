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
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
        for(int j=0;j<n;j++){
        	for(int i=j+1;i<n;i++){
                if(i + j < n)cout << i + 1 << ' ' << j+1 << '\n';
            }
        }
        //Does this really work??!?!
        for(int j=0;j<n;j++){
            for(int i=j+1;i<n;i++){
                if(i + j < n)cout << i + 1 << ' ' << j+1 << '\n';
            }
        }
    	
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/

/*

Start with defult them try to shift each pair backward
1 2
1 3
2 3
1 4
2 4
1 5
2 5
1 6
2 6
1 7
2 7
3 4
3 5
3 6
3 7
4 5
4 6
4 7
5 6
5 7
6 7

*/