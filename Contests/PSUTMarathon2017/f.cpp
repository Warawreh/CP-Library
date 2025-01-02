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
const int nax = 2e5 + 100;
int dp[nax][9][9][2];

int get(char c){
	if(c == 'R')return 1;
	if(c == 'G')return 2;
	return 4;
}

int calc(int i,int l,int h,){
	if((h | l) == 7)return (i != n);
	if(i == n)return 100;
	int &ret = dp[i][min(l,8)][h];
	if(ret != -1)return ret;
	ret = calc(i + 1,0 , h | (l <= 7 ? l : 0)) + 1;
	int cur = get(s[i]);
	if((cur & l) == 0){
		ret = min(ret , calc(i + 1,l | cur , h));
	}else{
		ret = min(ret , calc(i + 1,l + cur,h));
	}


	return ret;
}


int main(){
	fast
	cin>>s;
	n = s.size();
	memset(dp,-1,sizeof(dp));
	cout << calc(0,0,0) << '\n';
}