#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n), b(n);
    vector<int> id(n);
    iota(all(id), 0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];

    sort(all(id), [&](int x,int y){
        return b[x] < b[y];
    });
    
    int ans = 0;
    int startGCD = 0;
    int takeIt = 5;
    if(k > takeIt){
        reverse(all(id));
        for(int j=0;j<k-takeIt;j++){
            int i = id.back();
            id.pop_back();
            ans += b[i];
            startGCD = gcd(startGCD, a[i]);
        }
    }else takeIt = k;

    vector<vector<int>> dp(takeIt + 1, vector<int> (1010, 1e9));
    dp[0][startGCD] = 0;
    for(int j=0;j<id.size();j++){
        int i = id[j];
        for(int t=takeIt-1;t>=0;t--){
            for(int g=0;g<1001;g++){
                dp[t+1][gcd(g, a[i])] = min(dp[t+1][gcd(g, a[i])], dp[t][g] + b[i]);
            }
        }
    }

    if(ans + dp[takeIt][1] >= 1e9)cout << -1 << '\n';
    else cout << ans + dp[takeIt][1] << '\n';

}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}
