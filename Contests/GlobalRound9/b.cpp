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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> g(n,vector<int> (m)),a(n,vector<int>(m,1));
		bool can = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>g[i][j];
				a[i][j] = (i > 0) + (j > 0) + (i + 1 < n) + (j + 1 < m);
				if(g[i][j] > a[i][j])can = false;
			}
		}
		cout << (can ? "YES" :"NO") << '\n';
		if(can){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout << a[i][j] << " \n"[j == m-1];
				}
			}
		}
	}
}