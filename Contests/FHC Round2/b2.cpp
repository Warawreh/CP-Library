#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ld n,p;
ll dp[5050][5050];

ld calc(int a,int b){
	if(a == 0 && b == 0)return 1;
	ld &ret = dp[a][b];
	if(ret != -1)return ret;
	ret = 0;
	
	if(a && b){
		ret += calc(a-1,b-1) * a * b / tot;
	}
}

void solve(){
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cout << calc(i,n-i-1 ) << '\n';
	}
}

int main(){
	fast
	memset(dp,-1,sizeof(dp));
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}