#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int x,y,n;
string s;
vector<vector<int>> dp;

int calc(int i,int b){
	if(i == n)return 0;
	int &ret = dp[i][b];
	if(ret != 1e9)return ret;
	ret = 1e9 - 1;
	if(s[i] == 'C'){
		if(b == 1)ret = calc(i + 1 , 0) + y;
		else ret = calc(i + 1 , 0);
	}else if(s[i] == 'J'){
		if(b == 0)ret = calc(i + 1 , 1) + x;
		else ret = calc(i + 1 , 1);
	}else{
		if(b == 1)ret = calc(i + 1 , 0) + y;
		else ret = calc(i + 1 , 0);
		if(b == 0)ret = min(ret , calc(i + 1 , 1) + x);
		else ret = min(ret , calc(i + 1 , 1));
	}
	return ret;
}

int solve(){
	cin>>x>>y>>s;
	n = s.size();
	dp = vector<vector<int>>(n,vector<int>(3,1e9));
	return min(calc(0,0) , calc(0,1));
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": " << solve() << '\n';
	}
}