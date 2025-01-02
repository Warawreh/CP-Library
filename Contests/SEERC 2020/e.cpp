#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;
const int nax = 5e5 + 2;
ll dp[nax][3][3];

ll calc(int i,int s,int c){
	if(i == n)return 0;
	ll &ret = dp[i][s][c];
	if(ret != -1)return ret;

	ll ns = (s + c * a[i])%3;
	ret = !ns;
	ret = (ret + calc(i+1 , ns,(c + a[i])%3));
	return ret;
}

int main(){
    fast
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	a[i] %= 3;
    }
    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    for(int i=0;i<n;i++)
    	ans += calc(i,0,0);
    cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/