#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> v;
map<vector<int>,int> dp[15];
map<vector<int>,bool> vis[15];
int n;

int calc(int i,vector<int> m,int msk){
	if(i == n){
		return 1;
	}
	int &ret = dp[i][m];
	if(vis[i][m])return ret;
	ret = 0;
	for(int j=0;j<n;j++){
		if((msk >> j) & 1)continue;
		vector<int> tmp = m;
		int hv = 0;
		for(int x=0;x<tmp.size();x++){
			if(j + 1 > tmp[x]){
				tmp[x] = 1e9;
			}
		}
		tmp.push_back(j+1);
		for(int x=0;x<tmp.size();x++)if(tmp[x] != 1e9)hv++;
		if(hv != v[i])continue;
		ret += calc(i + 1,tmp , msk | (1 << j));
	}
	return ret;
}

void solve(){
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];
	// cerr << "TEST : " << n << '\n';
	cout << calc(0,{},0) << '\n';
	// cerr << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}