#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<vector<int>>> g,dp;

int calc(int i,int j,int k){
   if(i == -1)return 0;
   if(j == 10 || k == 10)return 0;
   int &ret = dp[i][j][k];
   if(ret != -1)return ret;
   ret = g[i][j][k] + max({calc(i-1,j,k) , calc(i,j+1,k) , calc(i,j,k+1)});
   return ret;
}

void solve(){
   int n;

   g = vector<vector<vector<int>>>(10,vector<vector<int>>(10,vector<int>(10,0)));
   dp = vector<vector<vector<int>>>(10,vector<vector<int>>(10,vector<int>(10,-1)));

   cin>>n;

   for(int i=0;i<n;i++){
      int a,b,c,h;
      cin>>a>>b>>c>>h;
      a--;b--;c--;
      g[a][b][c] += h;
   }

   cout << calc(9,0,0) << '\n';

}

int main(){
   fast
   freopen("commandos.in","r",stdin);
   int t;
   cin>>t;
   while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/