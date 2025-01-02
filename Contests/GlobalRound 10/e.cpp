#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	// fast
	int n;
	cin>>n;
	vector<vector<ll>> g(n,vector<ll>(n,0)),mn;
	ll sum = 0;
	for(int j=n-2;j>=0;j--){
		ll nxt = 0;
		for(int i=n-1;i>0;i--){
			ll w = 0;
			ll ww=0;
			for(int x=i-1;x<n - 1;x++)w += g[x][j+1];
			for(int x=j+1;x<n - 1;x++)ww += g[i][x];
			g[i][j] = w + 1 + sum - ww;
		}
		sum += g[n-1][j];
	}
	ll mx = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mx = max(mx , g[i][j]);
			cout << g[i][j] << ' ';
		}
		cout << '\n';
		fflush(stdout);
	}
	cerr << mx << '\n';
	mn = g;
	for(int i=n-1;i>0;i--){
		for(int j=n-2;j>=0;j--){
			mn[i][j] += mn[i][j+1];
			mx = max(mx , mn[i][j]);
			// cerr << mn[i][j] << ' ';
		}
		// cerr << '\n';
	}
	cerr << mx << '\n';
	int q;
	cin>>q;
	while(q--){
		ll v;
		cin>>v;
		vector<pair<int,int>> ans;
		int x=0,y=0;
		for(int i=0;i<2*n-2;i++){
			// cerr << x << ' ' << y << '\n';
			// if(x+1<n)cerr << v << ' ' << g[x+1][y] << '\n';
			ans.push_back({x,y});
			if(x + 1 < n && v >= mn[x+1][y]){
				x++;
			}else{
				y++;
			}
			v -= g[x][y];
		}
		ans.push_back({n-1,n-1});
		for(auto i : ans){
			cout << i.first+1 << ' ' << i.second+1 << '\n';
			fflush(stdout);
		}
		cout << '\n';
	}
}

/*
1 1
2 1
3 1
3 2
3 3
3 4
4 4
*/