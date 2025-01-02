#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
vector<int> a,b;
const int nax = 1010;
int dp[nax][nax];

int calc(int i,int j){
	if(i == n && j == m)return 0;
	int &ret = dp[i][j];
	if(ret != -1)return ret;
	ret = 1e9;
	if(i == n)ret = calc(i,j + 1) + 1;
	else if(j == m)ret = calc(i+1,j) + 1;
	else{
		ret = min(ret , (a[i] != b[j]) + calc(i+1,j+1));
		ret = min(ret , 1 + calc(i+1,j));
		ret = min(ret , 1 + calc(i,j+1));

	}
	return ret;
}

int main(){
	fast
	cin>>n>>m;
	a.resize(n);
	b.resize(m);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	memset(dp,-1,sizeof(dp));
	cout << calc(0,0) << '\n';
}