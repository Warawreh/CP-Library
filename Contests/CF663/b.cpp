#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
vector<string> s;
vector<vector<ll>> dp;

ll calc(int r,int c){
	if(r == n-1 && c == m-1)return 0;
	if(r >= n || c >= m)return 1e9;
	ll &ret = dp[r][c];
	if(ret != -1)return ret;
	if(s[r][c] == 'R')ret = min(1 + calc(r+1,c),calc(r,c+1));
	else ret = min(1 + calc(r , c + 1) , calc(r + 1 , c));
	return ret;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		s.clear();
		int ans = 0;
		for(int i=0;i<n;i++){
			string x;
			cin>>x;
			if(i == n-1){
				for(int j=0;j<m-1;j++)ans += x[j] != 'R';
			}else{
				ans += x.back() != 'D';
			}
		}
		cout << ans << '\n';
	}
}