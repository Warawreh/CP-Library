#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			while(a % 2 == 0){
				g[i][j].first++;
				a/=2;
			}
			while(a % 3 == 0){
				g[i][j].second++;
				a/=3;
			}
		}
	}
	vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(n+m * 10,-1)));
	dist[0][0][0] = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int t=0;t<dist[i][j].size();t++){
				if(dist[i][j][t] == -1)continue;
				if(i == n-1 && j == m-1){
					ans = max(ans , min(t + g[i][j].second , dist[i][j][t] + g[i][j].first));
				}
				if(i + 1 < n){
					dist[i+1][j][t + g[i][j].second] = max(dist[i+1][j][t+g[i][j].second] , dist[i][j][t] + g[i][j].first);
				}
				if(j + 1 < m){
					dist[i][j+1][t + g[i][j].second] = max(dist[i][j+1][t+g[i][j].second] , dist[i][j][t] + g[i][j].first);
				}
			}
		}
	}

	cout << ans << '\n';

}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/