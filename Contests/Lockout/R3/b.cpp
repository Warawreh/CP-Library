#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n,m;
	cin>>n>>m;
	vector<vector<int>> x(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>x[i][j];
	}
	int a,b;
	cin>>a>>b;
	ll ans = 1e9;
	swap(a,b);
	for(int i=0;i<=n-a;i++){
		for(int j=0;j<=m-b;j++){
			ll cur = 0;
			for(int l=i;l<i+a;l++){
				for(int r = j;r<j+b;r++)
					cur += x[l][r];
			}

			ans = min(ans , cur);
		}
	}
	swap(a,b);
	for(int i=0;i<=n-a;i++){
		for(int j=0;j<=m-b;j++){
			ll cur = 0;
			for(int l=i;l<i+a;l++){
				for(int r = j;r<j+b;r++)
					cur += x[l][r];
			}

			ans = min(ans , cur);
		}
	}
	cout << ans << '\n';
}