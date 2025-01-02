#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int sum[202][202][2002];

void solve(){
	int n,m,q;
	cin>>n>>m>>q;

	vector<vector<int>> x(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>x[i][j];

	for(int v=1;v<=2000;v++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				sum[i][j][v] = (x[i][j] <= v) + (i ? sum[i-1][j][v] : 0) + (j ? sum[i][j-1][v] : 0) - (i > 0 && j > 0 ? sum[i-1][j-1][v] : 0);
			}
		}
	}

	cout << '\n';
	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		r1--;c1--;r2--;c2--;

		int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
		int lo=1,hi=2000,ans = 1;
		while(lo <= hi){
			int md = (lo + hi)/2;

			int cur = sum[r2][c2][md] - (r1 ? sum[r1-1][c2][md] : 0) - (c1 ? sum[r2][c1-1][md] : 0) + (r1 > 0 && c1 > 0 ? sum[r1-1][c1-1][md] : 0);
			if(cur  + cur > cnt){
				hi = md-1;
				ans = md;
			}else lo = md+1;
		}
		cout << ans << '\n';
	}

}

int main(){
	fast
	freopen("important.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ": ";
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/