#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if(a < n+m-1 || b < n+m-1){
		cout << "Impossible\n";
		return;
	}
	vector<vector<int>> g(n,vector<int>(m,1000));
	for(int i=0;i<n;i++)g[i][0] = g[i][m-1] = 1;
	for(int i=0;i<m;i++)g[0][i] = 1;
	g[n-1][0] = b - (n+m-2);
	g[n-1][m-1] = a - (n+m-2);

	cout << "Possible\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cout << g[i][j] << " \n"[j == m-1];
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}	
}