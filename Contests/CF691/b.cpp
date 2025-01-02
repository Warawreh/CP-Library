#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 102;
short dp[nax][nax][nax*nax];
int n,tot;
vector<pair<int,int>> c;

// short calc(int i,int k,int b,int s){
// 	if(k < 0)return -32767;
// 	if(i == n){
// 		if(k == 0)return min(b+tot,s*2);
// 		else return -32767;
// 	}
// 	short &ret = dp[i][k][s];
// 	if(ret != -1)return ret;

// 	ret = max(calc(i + 1 , k , b , s) , calc(i + 1 , k - 1,b + c[i].second , s + c[i].first));
// 	// cerr << i << ' ' << k << '\n';
// 	// cerr << ret << ' ' << calc(i + 1 , k - 1,b , s + (c[i].first - c[i].second)*2) + c[i].second << '\n';
// 	return ret;
// }

int main(){
	fast
	cin>>n;
	c.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>c[i].first>>c[i].second;
		tot+=c[i].second;
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int v=0;v<=100*n;v++)dp[i][j][v] = -32768;
	dp[0][0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int v = 0;v<=100*n;v++){

				dp[i][j][v] = max( dp[i-1][j][v] , (short)((j && v >= c[i].first ? dp[i-1][j-1][v - c[i].first] : -32768) + c[i].second));
				// if(v == 10 && j == 1)cerr << dp[i][j][v] << ' ' << dp[i-1][j-1][v-c[i].first] << '\n';
			}
		}
	}
	for(int i=1;i<=n;i++){
		int ans = 0;
		for(int v=0;v<=100*n;v++){
			if(i == 1 && dp[n][i][v] > 0){
				// cerr << v << ' ' << min(v*2 , dp[n][i][v] + tot) << '\n';
			}
			ans = max(ans , min(v*2 , dp[n][i][v] + tot));
		}
		cout << setprecision(9) << fixed << ans/2.0 << ' ';
	}

	// for(int i=1;i<=n;i++){
	// 	cout << setprecision(9) << fixed << calc(0,i,0,0)/2.0 << ' ';
	// }
}