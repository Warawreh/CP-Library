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
    cout << setprecision(6) << fixed;
    ld d , v1 , v2 , v3 , t ; cin >> d >> v1 >> v2 >> v3 >> t ;
    ld cur = 0;
    ld pos = 0;
    int dir = 1;
    while(1){


        ld lo = 0,hi = 100,need = 0;
        for(int it=0;it<1000;it++){
            ld md = (lo +hi)/2;

            ld np = pos + dir * md * v3;

            if(dir == 1){
                ld p2 = 1 + v2 * (md + cur);
                p2 = min(p2 , d);
                if(np >= p2){
                    need = md;
                    hi = md;
                }else {
                    lo = md;
                }
            }else{
                ld p1 = v1 * (md + cur);
                p1 = min(p1 , d);
                if(np <= p1){
                    need = md;
                    hi = md;
                }else lo = md;
            }
        }

        if(v1 * (need + cur) >= d){
            cout << d << '\n';
            return 0;
        }
        if(need <= 1e-9){
            cout << min(d , 1 + t * v2) << '\n';
            return 0;
        }
        if(cur + need >= t){
            t -= cur;
            cout << min(d , pos + dir * t * v3) << '\n';
            return 0;
        }
        pos = pos + dir * need * v3;
        cur += need;
        dir = -dir;

    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/