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
	vector<string> s(n);
	vector<vector<int>> up(n,vector<int>(m)),down(n,vector<int>(m));
	vector<vector<int>> left(n,vector<int>(m)),right(n,vector<int>(m));
	for(int i=0;i<n;i++)cin>>s[i];
	for(int j=0;j<m;j++){
		int len = 0;
		for(int i=0;i<n;i++){
			if(i == 0 || s[i][j] != s[i-1][j])len = 1;
			else len++;
			up[i][j] = len;
		}
	}
	for(int j=0;j<m;j++){
		int len = 0;
		for(int i=n-1;i>=0;i--){
			if(i == n-1 || s[i][j] != s[i+1][j])len = 1;
			else len++;
			down[i][j] = len;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			left[i][j] = (j && s[i][j] == s[i][j-1] ? min(left[i][j-1] + 1 , min(up[i][j] , down[i][j])) : 1);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			right[i][j] = (j + 1 < m && s[i][j] == s[i][j+1] ? min(right[i][j+1] + 1 , min(up[i][j] , down[i][j])) : 1);
		}
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans += min(left[i][j] , right[i][j]);
			// cerr << i << ' ' << j << ' ' << left[i][j] << ' ' << right[i][j] << "\n";
		}
	}
	cout << ans << '\n';
}