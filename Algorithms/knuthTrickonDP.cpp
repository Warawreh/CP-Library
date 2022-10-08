/*
Tested: https://www.spoj.com/problems/BRKSTRNG/
*/

vector<vector<ll>> opt(n,vector<ll>(n)),dp(n,vector<ll>(n,1e16));
for(int i=1;i<n-1;i++){
    opt[i][i] = i;
    dp[i][i] = cut[i+1] - cut[i-1] ;
}

for(int i=n-2;i>0;i--){
    for(int j=i+1;j<n-1;j++){

        ll mn = 1e16;   
        ll cost = cut[j+1] - cut[i-1] ;

        for(int x=opt[i][j-1];x<=min(j - 0LL , opt[i+1][j]);x++){
            ll cur =  (x != i ?dp[i][x-1] : 0) + (x+1 <= j ? dp[x+1][j] : 0) + cost;

            if(cur < mn){
                mn = cur;
                opt[i][j] = x;
            }
        }

        dp[i][j] = mn;

    }
}

cout << dp[1][n-2] << '\n';