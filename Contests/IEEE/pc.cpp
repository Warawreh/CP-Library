#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

ll POW(ll a,ll b){
    if(!b)return 1;
    ll res = POW(a,b/2);
    res = (res * res)%mod;
    if(b % 2)res = (res * a)%mod;
    return res;
}

vector<ll> fact,inv;
void init_COM(int n){
   fact = inv = vector<ll>(n+1);
   fact[0] = inv[0] = 1;
   for(int i=1;i<=n;i++){
      fact[i] = (fact[i-1] * i) % mod;
      inv[i] = POW(fact[i] , mod-2);
   }
}
inline ll nCk(ll n, ll k){
    return ((fact[n] * inv[k])%mod * inv[n-k])%mod;
}
inline ll nPk(ll n,ll k){
    return (fact[n]*inv[n-k])%mod;
}


int main(){
    fast
    
    ll n,m;
    cin>>n>>m;
    init_COM(n);
    if(m == 1){
        cout << 1 << '\n';
        return 0;
    }
    vector<int> vals(n+2);
    vals[1] = m;
    for(int i=2;i<=n;i++){
        if(m - i + 1 <= 0)vals[i] = vals[i-1];
        else vals[i] = (vals[i-1] * 1LL * (m - i + 1))%mod;
        // cerr << vals[i] << ' ';
    }

    vector<int> dp(n+2);
    dp[0] = 1;
    for(int i=2;i<=n;i+=2){
        int at = 0;
        for(int j=i-2;j>=0;j-=2){
            at++;
            // if(at > m)break;
            dp[i] = (dp[i] + ((dp[j] * m)%mod * POW(m - 1,at - 1))%mod)%mod;
            cerr << i << ' ' << j << ' ' << dp[i] << '\n';
        }
    }
    cout << dp[n] << '\n';

}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/