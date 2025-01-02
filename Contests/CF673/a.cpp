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
		vector<int> a(n);
		vector<vector<int>> pos(n+1);
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(pos[a[i]].empty())pos[a[i]].push_back(-1);
			pos[a[i]].push_back(i);
		}
		vector<int> ans(n+1,-1);
		for(int i=1;i<=n;i++){
			if(pos[i].empty())continue;
			pos[i].push_back(n);
			int dist = 0;
			for(int j=1;j<pos[i].size();j++)dist = max(dist , pos[i][j] - pos[i][j-1]);
			if(ans[dist] == -1)ans[dist] = i;
		}
		for(int i=1;i<=n;i++){
			if(ans[i] == -1)ans[i] = ans[i-1];
			if(ans[i-1] != -1)ans[i] = min(ans[i] , ans[i-1]);
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}