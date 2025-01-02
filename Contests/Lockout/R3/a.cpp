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
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> a(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	if(k == 1){
		cout << m*(m-1)/2 << '\n';
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				cout << i << ' ' << j << '\n';
			}
		}
	}else{
		cout << m*(m-1)/2 << '\n';
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				cout << j << ' ' << i << '\n';
			}
		}
	}
}