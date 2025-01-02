#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int nax = 1002;
int dp[nax][nax];
int n,k;

int calc(int i,int j){
   if(i == n){
      return (j == k);
   }
   if(j > k)return 0;
   int &ret = dp[i][j];
   if(ret != -1)return ret;
   ret = ((calc(i + 1, j + 1) * 1LL * (k - j))%mod + (calc(i + 1 , j ) * 1LL * j) % mod)%mod;
   return ret;
}

int main(){
   fast
   freopen("galactic.in","r",stdin);
   int t;
   cin>>t;
   while(t--){
      cin>>n>>k;


      if(k > n){
         cout << 0 << '\n';
      }else{
         for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++)
               dp[i][j] = -1;
         cout << calc(0,0) << '\n';
      }
   }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/