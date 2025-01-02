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
    
    string s;
    while(cin>>s){
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int l=n-1;l>=0;l--){
            for(int r=l+1;r<n;r++){
                if(s[i] == s[j])dp[i][j] = 1;
            }
        }

        for(int l=n-1;l>=0;l--){
            for(int r=l+1;r<n;r++){
                if(l){
                    if(s)
                }
            }
        }
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/