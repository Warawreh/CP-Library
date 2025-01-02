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
    int toa = 100;
    int cnt = 0;
  	for(int a=1;a<=toa;a++){
  		for(int b=a;b<=toa;b++){
  			cnt++;
  			cout << 3 << ' ' << a << ' ' << b << '\n';
  		}
  	}  
  	cerr << cnt << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/