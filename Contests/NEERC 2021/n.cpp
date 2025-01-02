#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 55;
ll dp[nax][nax][2];
ll n,k;

ll calc(int i,int on,bool w){
    if(on < 0)return 0;
    if(i == (n + 1)/2){
        return (on == 0);
    }
    ll &ret = dp[i][on][w];
    if(ret != -1)return ret;
    ret = calc(i+1,on,w) + calc(i+1,on-1,1) * (w && (n % 2 == 0 || i != n / 2) ? 2 : 1);
    if(n % 2 == 0 || i != n / 2){
        ret += calc(i+1,on-2,w);
        // cerr << 1 << '\n';
    }
    // cerr << i << ' ' << on << ' ' << ret << '\n';
    return ret;
}

int main(){
    fast
    cin>>n>>k;

    ll res = 0;
    vector<ll> hv(k+1);
    for(int i=0;i<=k;i++){
        memset(dp,-1,sizeof(dp));
        hv[i] = calc(0,i,0);

        if(k - i <= n && k - i >= 0)
            res += hv[i];
        // cerr << hv[i] << ' ';
    }
    
    if(k % 2 == 0)res += hv[k/2];
    cout << res << '\n';
}
