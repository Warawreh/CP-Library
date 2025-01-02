#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 102;
int dp[nax][nax][nax*nax];
vector<pair<int,int>> a;
int n,tot;

int calc(int i,int c,int s){
	if(i == n){
		if(c == 0){
			return min(s, tot);
		}
		else return -1e9;
	}
	if(c < 0)return -1e9;
	int &ret = dp[i][c][s];
	if(ret != -1)return ret;

	ret = max(calc(i + 1,c , s) , calc(i + 1,c-1, s + 2*a[i].first - a[i].second) + a[i].second);
	return ret;
}

int main(){
	fast
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		tot += a[i].second;
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		cout << setprecision(12) << fixed << calc(0,i,0)/2.0 << ' ';
	}
}