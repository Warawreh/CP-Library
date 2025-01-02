#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k;
string s,t;
const int nax = 202;
ll dp[nax][nax][nax];

ll calc(int i,int u,ll h){
	if(i == n)return 0;
	ll &ret = dp[i][u][h];
	if(ret != -1)return ret;
	ret = h * (s[i] == t[1]) + calc(i+1,u,h + (s[i] == t[0]));
	if(u != k){
		ret = max(ret , calc(i+1,u+1,h+1) + h * (t[0] == t[1]));
		ret = max(ret , calc(i+1,u+1,h+(t[1] == t[0])) + h);
	}

	return ret;
}

int main(){
	fast
	cin>>n>>k>>s>>t;
	memset(dp,-1,sizeof(dp));
	cout << calc(0,0,0) << '\n';
}