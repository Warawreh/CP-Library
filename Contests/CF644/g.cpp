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
	if(n*a != m*b){
		cout << "NO\n";
	}else{
		cout << "YES\n";
		vector<vector<int>> g(n,vector<int> (m));
		for(int i=0;i<n;i++){
			for(int j=0;j<a;j++){
				g[i][(j + i * a + b)%m] = 1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << g[i][j];
			}
			cout << '\n';
		}
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}