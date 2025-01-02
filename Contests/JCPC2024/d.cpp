#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll getSum(ll v){
    ll result = 0;
    ll po = 5;
    while (po <= v){
        ll x = ((v - po + 1) / po) * po + (po - 1); 
        ll foo = x / po;
        result += ((foo * (foo + 1)) / 2) * po;
        ll d = v / po;
        result += d * (v - x); 
        po *= 5;   
    }
    // ll x = ((v - 1) / 5) * 5 + 4;
    // cerr << x << endl;
    
    
    // while(po <= x){
    //     ll foo = x / po;
        
    //     result += ((foo * (foo + 1)) / 2) * po;
    //     po *= 5;
    // }
    // po = 5;
    // ll d = 0;
    // while(po <= v){
    //     d += v / po;
    //     po *= 5;
    // }
    
    // result += d * (v - x);

    return result;
}

void solve(){
    ll l, r;
    cin >> l >> r;
    cout << getSum(r) - getSum(l - 1) << endl;
    
}

int main(){
    int q;
    cin >> q;
    while(q--) solve();
}
