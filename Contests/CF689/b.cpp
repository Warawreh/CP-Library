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
		vector<string> s(n);
		for(int i=0;i<n;i++)cin>>s[i];
		vector<vector<vector<int>>> b(n,vector<vector<int>>(m,vector<int>(3)));
		for(int i=0;i<n;i++){
			int cnt = 0;
			for(int j=0;j<m;j++){
				if(s[i][j] == '*')cnt++;
				else cnt = 0;
				b[i][j][0] = cnt;
			}
			cnt = 0;
			for(int j=m-1;j>=0;j--){
				if(s[i][j] == '*')cnt++;
				else cnt = 0;
				b[i][j][1] = cnt;
			}
		}

		ll ans = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int lvl = min(b[i][j][0] , b[i][j][1]);
				if(i)lvl = min(lvl , b[i-1][j][2] + 1);
				else lvl = min(lvl , 1);
				ans += lvl;
				// cerr << i << ' ' << j << ' ' << lvl << '\n';
				b[i][j][2] = lvl;
			}
		}
		cout << ans << '\n';
	}
}