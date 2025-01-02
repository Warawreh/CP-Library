#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1010;
const int mod = 1e9 + 7;
ll dp[nax][nax];
int n;

ll calc(int i,int s,){
	if(s < 0)return 0;
	if(i > n)return 0;
	if(i == n)return !s;
	ll &ret = dp[i][s];
	if(ret != -1)return ret;
	ret = (calc(i+1,s+1,0) + calc(i+1,s-1,0) + calc(i+5,s + 1,1))%mod;
	return ret;
}

int main(){
    fast
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout << calc(0,0) << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/