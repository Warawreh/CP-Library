#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,k;
vector<vector<int>> g;
const int nax = 72;
int dp[nax][nax][nax/2][nax];

int calc(int r,int c,int t,int s){
	if(t > m/2)return -1e9;
	if(r == n){
		if(s == 0)return 0;
		else return -1e9;
	}
	if(c == m){
		return calc(r+1,0,0,s);
	}
	int &ret = dp[r][c][t][s];
	if(ret != -1)return ret;
	ret = max(calc(r, c + 1,t,s) , g[r][c] + calc(r, c + 1, t + 1,(s + g[r][c]) % k ) );
	return ret;
}

int main(){
	fast
	cin>>n>>m>>k;
	g.resize(n,vector<int> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout << max(0 , calc(0,0,0,0)) << '\n';
}