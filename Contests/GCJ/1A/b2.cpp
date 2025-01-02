#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a;
map<vector<int>,int> dp[101],vis[101];
int sum = 0;

int calc(int i,vector<int> v,int s,int p){
	if(p + s > sum)return 0;
	if(i == a.size()){
		if(p + s == sum)return p;
		else return 0;
	}
	int &ret = dp[i][v];
	if(vis[i][v])return ret;
	vis[i][v] = 1;
	ret = calc(i + 1,v,s,p);
	v.push_back(a[i]);
	s += a[i];
	p *= a[i];
	ret = max(ret , calc(i + 1,v,s,p));
	return ret;
}

void solve(){
	int m;
	cin>>m;
	a.clear();
	for(int i=0;i<101;i++){
		dp[i].clear();
		vis[i].clear();
	}
	sum = 0;
	for(int i=0;i<m;i++){
		int p,c;
		cin>>p>>c;
		for(int j=0;j<c;j++){
			a.push_back(p);
			sum += p;
		}
	}
	//dp = vector<vector<int>>(a.size() , vector<int> (500 * a.size(),-1));
	cout << max(0,calc(0,{},0,1)) << '\n';
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