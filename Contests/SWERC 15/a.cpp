#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g,rev;
vector<int> in,inr;
int a,b,e,p;

int solve(int k){
	int ans = 0;
	vector<int> inr = ::inr;
	vector<int> dp(e);
	vector<int> hd;
	int cur = 0;
	queue<int> q;
	for(int i=0;i<e;i++){
		if(inr[i] == 0){
			q.push(i);
			dp[i] = 1;
			if(dp[i] > hd.size())hd.push_back(0);
			hd[dp[i] - 1]++;
		}
	}
	while(q.size()){
		int u = q.front();
		// cerr << u << ' ' << dp[u] << '\n';
		q.pop();
		for(int v : rev[u]){
			inr[v]--;
			dp[v] = max(dp[v],dp[u] + 1);
			if(inr[v] == 0){
				if(dp[v] > hd.size())hd.push_back(0);
				hd[dp[v] - 1]++;
				q.push(v);
			}
		}
	}
	for(int i=hd.size()-1;i>=0;i--){
		// cerr << i << ' ' << hd[i] << '\n';
		if(i >= k)ans += hd[i];
	}
	return ans;
}

int bad(int k){
	vector<int> in = ::in;
	vector<int> dp(e);
	vector<int> hd(e+1);
	int cur = 0;
	queue<int> q;
	for(int i=0;i<e;i++){
		if(in[i] == 0){
			q.push(i);
			dp[i] = 1;
			hd[dp[i] - 1]++;
		}
	}
	while(q.size()){
		int u = q.front();
		// cerr << u << ' ' << dp[u] << '\n';
		q.pop();
		for(int v : g[u]){
			in[v]--;
			if(in[v] == 0){
				dp[v] = dp[u] + 1;
				hd[dp[v] - 1]++;
				q.push(v);
			}
		}
	}
	int ans = 0;
	for(int i=hd.size() - 1;i>=0;i--){
		if(hd[i] > k)break;
		cerr << i << ' ' << hd[i] << '\n';
		k -= hd[i];
		ans += hd[i];
	}
	return ans;
	return 0;
}

int main(){
	fast
	cin>>a>>b>>e>>p;
	in.resize(e);
	g.resize(e);
	rev.resize(e);
	inr.resize(e);
	for(int i=0;i<p;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		rev[v].push_back(u);
		in[v]++;
		inr[u]++;
	}
	// cerr << solve(b) << '\n';
	cout << solve(e - a) << '\n' << solve(b) << '\n' << bad(b);

}