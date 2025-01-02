#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> dp;
vector<int> a;
int n;

int calc(int i,int t){
	if(t > n*2)return 1e9;
	if(i == n)return 0;
	int &ret = dp[i][t];
	if(ret != -1)return ret;
	ret = min(calc(i+1,t+1) + abs(a[i] - t) , calc(i,t+1));
	return ret;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(all(a));
		dp = vector<vector<int>>(n,vector<int>(2*n+1,-1));
		cout << calc(0,1) << '\n';
	}
}