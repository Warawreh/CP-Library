#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prime,val;
vector<bool> is_composite;

void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

map<vector<int> , bool > dp,vis;
bool solve(vector<int> a){
	if(a.empty())return false;
	if(vis[a])return dp[a];
	vis[a] = 1;
	dp[a] = 0;
	int l = 0;
	for(int s : a)l = max(l , s);


	bool fnd = false;
	bool win = false;
	for(int p : prime){
		if(win)break;
		if(p > (l + 1)/2)break;
		fnd = true;

		for(int j=0;j<a.size();j++){
			if(win)break;
			if(p > a[j])continue;
			vector<int> tmp = a;
			tmp.erase(tmp.begin() + j);
			for(int x=0;x+p <= a[j];x++){
				if(win)break;
				if(x)tmp.push_back(x);
				if(a[j] - x - p > 0)tmp.push_back(a[j] - x - p);
				if(solve(tmp) == false){
					win = true;
				}
				if(x)tmp.pop_back();
				if(a[j] - x - p > 0)tmp.pop_back();
			}
		}
	}
	if(!fnd){
		int p = 1;
		for(int j=0;j<a.size();j++){
			if(win)break;
			if(p > a[j])continue;
			vector<int> tmp = a;
			tmp.erase(tmp.begin() + j);
			for(int x=0;x+p <= a[j];x++){
				if(win)break;
				if(x)tmp.push_back(x);
				if(a[j] - x - p > 0)tmp.push_back(a[j] - x - p);
				if(solve(tmp) == false){
					win = true;
				}

				if(x)tmp.pop_back();
				if(a[j] - x - p > 0)tmp.pop_back();
			}
		}
	}
	if(win)dp[a] = 1;

	// cerr << a.size() << ' ' << a[0] << ' ' << dp[a] << '\n';
	return dp[a];
}

int main(){
	fast
	sieve(1000);
	// cerr << solve({8}) << '\n';
	for(int i=1;i<=1000;i++){
		if(solve({i}) == 0)cerr << i << '\n';
		// cerr << i << ' ' << (solve({i}) ? "first" : "second") << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/