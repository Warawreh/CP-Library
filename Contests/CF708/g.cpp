#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prime,val;
vector<bool> is_composite;

void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}



int main(){
	fast
	sieve((int)3164);
	

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		map<int,int> hv;
		vector<vector<int>> dp(k+1,vector<int>(n,(int)1e9));
		dp[0][0] = 1;
		set<int> stops;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			int v = 1;
			for(int p : prime){
				if(p > a)break;
				if(a % p)continue;
				int cnt = 0;
				while(a % p == 0){
					a/=p;
					cnt++;
				}
				if(cnt){
					cnt%=2;
					if(cnt)v*=p;
				}
			}
			if(a)v*=a;

			if(hv[v]){
				stops.insert(-hv[v]);
				//for(int a : stops)cout << a << ' ';
				//cout << " _ ";
				if(stops.size() > k + 1)stops.erase(--stops.end());
				//for(int a : stops)cout << a << ' ';
				//cout << '\n';
				int j = 0;
				for(int j=0;j<=k;j++)dp[j][i] = min(dp[j][i] , dp[j][i-1] + 1);
				// cout << stops.size() << ':';
				for(int u=0;u<=k;u++){
				    j = 0;
					for(int at : stops){
						at = -at;
						at--;
						//if(i == 8)cout << at << ' ' << j << '\n';
						if(u >= j){
							dp[u][i] = min(dp[u][i],dp[u-j][at] + 1);
						}else break;
						// if(i == 5)cerr << j+1 << ' ' << at << ' ' << dp[j][at] << ' ' << dp[j+1][i] << '\n';
						j++;
					}
					//cout << j << ' ';
					if(u >= j){
						dp[u][i] = min(dp[u][i],1);
					}
				//	cout << i << ' '<<dp[u][i] << '\n';
				}
			//	cout << '\n';
			}else{
				for(int j=0;j<=k;j++){
					if(i)dp[j][i] = min(dp[j][i],dp[j][i-1]);
				}
			}
			for(int j=1;j<=k;j++){
				dp[j][i] = min(dp[j][i] , dp[j-1][i]);
			}
			
			 if(0){
			 	for(int j=0;j<=k;j++){
			 		cout << dp[j][i] << ' ';
			 	}
			 	cout << '\n';
			 }
			hv[v] = i + 1;
		}
		int ans = 1e9;
		for(int i=0;i<=k;i++)ans = min(ans , dp[i][n-1]);
		cout << ans << '\n';
	}
}