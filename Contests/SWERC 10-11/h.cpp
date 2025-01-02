#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<int,int>>> g;
int n;

void init(){
	g.clear();
	g = vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(n));
}

vector<int> a;
vector<int> dp[202][202];

void solve(int l,int r){
	if(dp[l][r].size())return;
	if(l == r){
		dp[l][r] = vector<int>(n,1e9);
		dp[l][r][a[l]] = 0;
		return;
	}

	dp[l][r] = vector<int>(n,1e9);
	for(int md=l;md<r;md++){

		solve(md+1,r);
		solve(l,md);
		vector<int> &lhs = dp[l][md];
		vector<int> &rhs = dp[md+1][r];

		for(int cur=0;cur<n;cur++){
			for(int j=0;j<n;j++){
				int to = g[cur][j].first;
				int nCst = lhs[cur] + g[cur][j].second + rhs[j];
				dp[l][r][to] = min(dp[l][r][to] , nCst);
			}
		}

	}
	return;
}

int main(){
	fast
	while(1){
		cin>>n;
		if(!n)break;
		init();
		vector<char> ord(n);
		for(int i=0;i<n;i++)cin>>ord[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				string cur;
				cin>>cur;
				char toC = cur.back();
				cur.pop_back();
				cur.pop_back();
				int w = stoi(cur);
				int to = -1;
				for(int x=0;x<n;x++)if(toC == ord[x])to = x;
				assert(to != -1);
				g[i][j] = {to,w};
			}
		}
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;

			for(int x=0;x<s.size();x++)
				for(int y=x;y<s.size();y++){
					dp[x][y].clear();
				}

			a.clear();
			for(int j=0;j<s.size();j++){
				for(int x=0;x<n;x++){
					if(s[j] == ord[x]){
						a.push_back(x);
						break;
					}
				}
			}
			assert(a.size() == s.size());

			// int sz = a.size();

			// for(int l=sz-1;l>=0;l--){
			// 	for(int r=l;r<sz;r++){}
			// }

			solve(0,a.size() - 1);
			vector<int> res = dp[0][a.size() - 1];
			int best = 0;
			for(int j=0;j<n;j++){
				if(res[j] < res[best])best = j;
			}

			cout << res[best] << '-' << ord[best] << '\n';

		}
		cout << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/