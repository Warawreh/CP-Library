#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1000;
int dp[nax][nax];

int main(){
	fast
	dp[0][0] = 1;
	for(int n=0;n<nax;n++){
		int cnt = 0;
		for(int m=0;m<=n;m++){
			if(n && m)dp[n][m] += dp[n-1][m-1];
			if(n)dp[n][m] += dp[n-1][m];
			dp[n][m] %= 2;
			if(dp[n][m] % 2 == 0){
				cout << n << ' ' << m << '\n';
				cnt++;
			}
		}
		cerr << n << ' ' << cnt << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/