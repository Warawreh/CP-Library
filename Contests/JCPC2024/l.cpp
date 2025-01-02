
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
    fast
    int N = 1e3;
    vector< int > answer( N , -1 );
    for( int i = 2 ; i < N ; i ++ ){
        if( answer[i] == -1 ){
            answer[i] = 0;
            for( int j = 2*i ; j < N ; j+= i ){
                if( answer[j] == -1 ) answer[j] = answer[j-i] + answer[i] + 1;
                else answer[j] = min( answer[j] , answer[j-i] + answer[i] + 1 );
            }
        }
    }

    vector< int > primes;
    for( int i = 2 ; i < N ; i++ ){
        if( answer[i] == 0 ){
            primes.push_back( i );
        }else{
            
        }
    }

    cerr << primes.size() << '\n';
    return 0;

    int n;
    cin >> n;
    int ans = 0;
    while( n-- ){
        int x;
        cin >> x;
        if(answer[x] == -1)answer[x] = 2;
        ans += answer[x];
        // cout << x << " " << answer[x] << endl;
    }
    cout << ans << endl;

}
