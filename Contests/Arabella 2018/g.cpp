#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(m));

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];
	
	vector<vector<int>> UL,UR,DL,DR;
	UL = DR = DL = UR = g;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)	
			UL[i][j] = max({UL[i][j] , (i ? UL[i-1][j] : 0) , (j ? UL[i][j-1] : 0)});

	for(int i=0;i<n;i++)
		for(int j=m-1;j>=0;j--)	
			UR[i][j] = max({UR[i][j] , (i ? UR[i-1][j] : 0) , (j + 1 < m ? UR[i][j+1] : 0)});

	for(int i=n-1;i>=0;i--)
		for(int j=0;j<m;j++)	
			DL[i][j] = max({DL[i][j] , (i+1 < n ? DL[i+1][j] : 0) , (j ? DL[i][j-1] : 0)});

	for(int i=n-1;i>=0;i--)
		for(int j=m-1;j>=0;j--)	
			DR[i][j] = max({DR[i][j] , (i+1 < n ? DR[i+1][j] : 0) , (j+1 < m ? DR[i][j+1] : 0)});

	ll ans = 1e18;
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			vector<int> vals = {UL[i-1][j-1] , UR[i-1][j+1] , DL[i+1][j-1] , DR[i+1][j+1]};
			sort(all(vals));
			ans = min(ans , vals[3] - vals[0] + 0LL);
		}
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/