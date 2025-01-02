#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>g[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			if(j != m-1)cout << ' ';
			cout << g[i][j];
		}
		cout << '\n';
	}
}