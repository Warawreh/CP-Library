#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
string s;

void solve(){
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>g[i][j];
			g[i][j]--;
		}
	}
	cin>>s;
	vector<int> c(3,0);
	vector<int> v = {0,1,2};
	for(int i=0;i<m;i++){
		if(s[i] == 'R'){
			c[v[1]]++;
		}else if(s[i] == 'L'){
			c[v[1]]--;
		}else if(s[i] == 'U'){
			c[v[0]]--;
		}else if(s[i] == 'D'){
			c[v[0]]++;
		}else if(s[i] == 'I'){
			swap(v[1] , v[2]);
		}else if(s[i] == 'C'){
			swap(v[0] , v[2]);
		}else assert(0);
	}
	for(int i=0;i<3;i++)c[i] = ((c[i] % n) + n)%n;
	// cerr << p.first << ' ' << p.second << '\n';
	// cerr << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
	vector<vector<int>> ans = g;
	// return;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			vector<int> w = {i,j,g[i][j]};
			int x = (c[v[0]] + w[v[0]])%n;
			int y = (c[v[1]] + w[v[1]])%n;
			int val = (c[v[2]] + w[v[2]])%n;
			// cerr << w[v[0]] << ' ' << w[v[1]] << '\n';
			// cerr << x << ' ' << y << ' ' << val << '\n';
			ans[x][y] = val;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cout << ans[i][j] + 1 << " \n"[j==n-1];
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}