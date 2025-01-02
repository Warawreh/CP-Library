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
		int n;
		cin>>n;
		vector<vector<int>> a(3,vector<int>(n));
		for(int i=0;i<3;i++){
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		}
		vector<int> ans(n,-1);
		for(int j=0;j<n;j++){
			int taken = -1;
			for(int i=0;i<3;i++){
				if(a[i][j] == ans[(j+1)%n] || (j && a[i][j] == ans[j-1]))continue;
				taken = a[i][j];
				break;
			}
			cout << taken << ' ';
			ans[j] = taken;
		}
		cout << '\n';
	}
}