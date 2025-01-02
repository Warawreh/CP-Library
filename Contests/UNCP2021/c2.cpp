#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int SZ> struct HASH{
    const int mod = 1e9+7;
    int p[2] = {31,37};
    ll inv[2][SZ],POW[2][SZ],sum[2][SZ];
    ll Pow(ll a,ll b){
        if(!b)return 1;
        ll ret = Pow(a,b/2);
        if(b%2)return ((ret*ret)%mod*a)%mod;
        return (ret*ret)%mod;
    }   
    HASH(){
        POW[0][0] = POW[1][0] = 1;
        inv[0][0] = inv[1][0] = Pow(POW[0][0],mod-2);
        for(int i=1;i<SZ;i++){
            for(int x=0;x<2;x++){
                POW[x][i] = (POW[x][i-1] * p[x]) % mod;
                inv[x][i] = Pow(POW[x][i],mod-2);
            }
        }

    }
    void build(string s){
        for(int i=0;i<s.size();i++){
            for(int x=0;x<2;x++){
                sum[x][i+1] = ((s[i] - 'a' + 1) * POW[x][i])%mod;
                sum[x][i+1] = (sum[x][i+1] + sum[x][i]) %mod;
            }
        }
    }
    pair<int,int> check(int l,int r){
        ll h1 = ((sum[0][r+1] - sum[0][l] + mod)%mod * inv[0][l])%mod;
        ll h3 = ((sum[1][r+1] - sum[1][l] + mod)%mod * inv[1][l])%mod;
        return {h1,h3};
    }
    bool check(int l1,int r1,int l2,int r2){
        ll h1 = ((sum[0][r1+1] - sum[0][l1] + mod)%mod * inv[0][l1])%mod;
        ll h2 = ((sum[0][r2+1] - sum[0][l2] + mod)%mod * inv[0][l2])%mod;
        ll h3 = ((sum[1][r1+1] - sum[1][l1] + mod)%mod * inv[1][l1])%mod;
        ll h4 = ((sum[1][r2+1] - sum[1][l2] + mod)%mod * inv[1][l2])%mod;
        return h1==h2 && h3==h4;
    }

};

ll sum(ll a){
    return a * (a+1)/2;
}

int main(){
    fast
    HASH<5005> h;
    
    string s;
    while(cin>>s){
        h.build(s);
        int n = s.size();
        ll ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int l=n-1;l>=0;l--){
            for(int r=l+1;r<n;r++){
                if(s[l] == s[r]){
                    dp[l][r] = 1 + dp[l+1][r+1];
                }else{
                    dp[l][r] = 0;
                }
                // cerr << l << ' ' << r << ' ' << dp[l][r] << '\n';
            }
        }
        // break;

        for(int l=0;l<n;l++){
            int cur = l;
            for(int r=l+1;r<n;r++){

                int mx = dp[l][r] - 1;
                // cerr << l << ' ' << r << ' ' << mx << '\n';

                int fr=r,to=r+mx;
                // cerr << l << ' ' << r << ' ' << cur << ' ' << to << '\n';

                if(mx != -1 && to > cur){
                    ans += sum(mx + 1) - (cur >= fr ? sum(cur - fr + 1) : 0LL);
                    cur = to;
                }
            }
        }
        cout << ans << '\n';

    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/