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
    cout << setprecision(2) << fixed;
    int n ; cin >> n ;
    vector<int> v(n);
    vector< string > s(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> s[i] ;
        cin >> v[i] ;
        v[i] *= 100 ;
    }

    for(int mx = 49;mx>=-50;mx--){

        ll sum = 0;

        for( int i = 0 ; i < n ; i++ )
            sum += min( v[i] + mx , 10000 );


        if(sum < 10000){
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        for( int i = -50 ; i <= mx; i++ ){
            ll sum2 = 0;
            for( int j = 0 ; j < n ; j++ ){
                sum2 += max(0 , v[j] + i);
            }

            bool good = true;
            for(int j=0;j<n;j++){
                int cur = min( v[j] + mx , 10000 );
                int nxt = min(10000 , max(0 , v[j] + i));

                // if(mx == -50)cerr << sum - cur + nxt << ' ' << sum2 - nxt + cur << ' ' << good << '\n';
                if(sum - cur + nxt < 10000)good = false;
                if(sum2 - nxt + cur > 10000)good = false;
            }
            // if(mx == -50)cerr << sum2 << ' ' << good << '\n';

            if(sum2 <= 10000 && good){
                for( int w = 0 ; w < n ; w++ ){
                    cout << s[w] << " " ;
                    cout << ld(min(10000,max(0 , v[w] + i)))/100.0 << " " << ld(min(v[w]+mx , 10000 ) )/100.0 << endl;
                }
                // cout << i << ' ' << sum2 << ' ' << sum << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    // if( val < 0 || 99 < val ){
    // }else{
    
    // }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/