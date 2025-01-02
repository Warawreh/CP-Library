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
	int _;
	cin>>_;
	while(_--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> g(n,vector<int>(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>g[i][j];
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int &cur = g[i][j];
				if((i+j)%2 != (cur % 2)){
					cur++;
				}
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << g[i][j] << ' ';		
			}
			cout << '\n';
		}
	}
}