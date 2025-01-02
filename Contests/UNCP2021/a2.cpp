#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 505;
int dist[nax][nax][nax];

int main(){
    fast
    for( int i = 0 ; i < 50 ; i++ ){
        for( int j = 0 ; j <5000 ;j++ )cout <<'a';
            cout << endl;
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/