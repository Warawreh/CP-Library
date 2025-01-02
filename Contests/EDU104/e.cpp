#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<pair<int,int>,bool> e[3];

int main(){
	fast
	vector<int> n(4);
	for(int i=0;i<4;i++)cin>>n[i];
	vector<vector<int>> c(4);
	for(int i=0;i<4;i++){
		c[i].resize(n[i]);
		for(int j=0;j<n[i];j++)cin>>c[i][j];
	}
	for(int i=0;i<3;i++){
		int m;
		cin>>m;
		for(int j=0;j<m;j++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			// cerr << i << ' ' << a << ' ' << b << '\n';
			e[i][{a,b}] = true;
		}
	}
	vector<pair<ll,int>> dp,nxt;
	for(int i=0;i<n[3];i++)dp.push_back({c[3][i],i});
	for(int lvl=2;lvl>=0;lvl--){
		sort(all(dp));
		for(int i=0;i<n[lvl];i++){
			for(int j=0;j<dp.size();j++){
				if(e[lvl][{i,dp[j].second}])continue;
				nxt.push_back({c[lvl][i] + dp[j].first , i});
				break;
			}
		}
		dp = nxt;
		nxt.clear();		
	}
	sort(all(dp));
	if(dp.empty())cout << -1 << '\n';
	else cout << dp[0].first << '\n';

}