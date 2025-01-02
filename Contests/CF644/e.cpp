#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	cin>>n;
	vector<string> s(n);
	for(int i=0;i<n;i++)cin>>s[i];
	vector<vector<bool>> good(n,vector<bool> (n));
	// for(int it = 0;it<n;it++){
		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				if(s[i][j] == '0')continue;
				if(i == n-1){
					good[i][j] = 1;
				}else{
					if(good[i+1][j] == 1)good[i][j] = 1;
				}
				if(j == n-1){
					good[i][j] = 1;
				}else{
					if(good[i][j+1] == 1)good[i][j] = 1;	
				}
			}
		}
	// }
	bool can = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j] == '1' && !good[i][j])can = 0;
		}
	}
	cout << (can ? "YES\n" : "NO\n");
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}