#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e6 + 10;

vector<vector<int>> divisors;
map<pair<int,int>,int> dp;
map<pair<int,int>,bool> vis;

int calc(int n,int lst){
	if(n == 0)return 0;	
	if(n < 0)return (int)-1e9;
	pair<int,int> g = {n,lst};
	int &ret = dp[g];
	if(vis[g])return ret;
	ret = -1e9;
	vis[g] = 1;
	for(int p : divisors[lst]){
		// assert(p != lst);
		ret = max(ret , calc(n - p,p) + 1);
	}
	return ret;	
}

int n = 1;
void solve(){
	// n++;
	cin>>n;
	int ans = 1;
	for(int i=n-1;i>=4;i--){
		if(divisors[i].size() <= ans * 2)continue;
		ans = max(ans , calc(n - i , i) + 1);
	}
	cout << ans << '\n';
}

int main(){
	fast

	int sum = 0,cnt = 0;
	divisors.resize(nax);
	for(int i=3;i<nax;i++){
		for(int j=i+i;j<nax;j+=i){
			divisors[j].push_back(i);
		}
	}
	
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}

