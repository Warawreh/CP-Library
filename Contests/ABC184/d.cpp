#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ld dp[111][111][111];
bool vis[111][111][111];

ld calc(int a,int b,int c){
	if(a == 100 || b == 100 || c == 100)return 0;
	ld &ret = dp[a][b][c];
	if(vis[a][b][c])return ret;
	vis[a][b][c] = 1;
	ld tot = a+b+c;
	ret = 0;
	if(a)ret += calc(a+1,b,c) * a + a;
	if(b)ret += calc(a,b+1,c) * b + b;
	if(c)ret += calc(a,b,c+1) * c + c;
	// cerr << ret << ' ' << tot << '\n';
	ret /= tot;	
	// ret++;
	return ret;
}

int main(){
	fast
	cerr << setprecision(3) << fixed;
	// memset(dp,-1,sizeof(dp));
	int a,b,c;
	cin>>a>>b>>c;
	cout << setprecision(12) << fixed << calc(a,b,c) << '\n';
}