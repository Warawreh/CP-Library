#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
int n;
const int nax = 2e5 + 10;
int dp[nax][2];

int calc(int i,bool u){
	if(i == n)return 0;
	int &ret = dp[i][u];
	if(ret != -1)return ret;
	ret = 1e9;
	ret = 2 + calc(i , !u);
	if(s[i] == ' ' || isupper(s[i]) == u){
		ret = min(ret , 1 + calc(i + 1 , u));
	}else{
		ret = min(ret , 2 + calc(i + 1 , u));
	}
	return ret;
}

int main(){
	fast
	getline(cin,s);
	n = s.size();
	memset(dp,-1,sizeof(dp));
	cout << calc(0,0) << '\n';
}