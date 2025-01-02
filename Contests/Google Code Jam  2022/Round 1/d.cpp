#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

unordered_map<ll,int> dp[12],vis[12];
int at;

void solve(){
	at++;

	int e,w;
	cin>>e>>w;
	vector<vector<int>> g(e,vector<int> (w));
	for(int i=0;i<e;i++){
		for(int j=0;j<w;j++){
			cin>>g[i][j];
		}
	}

	priority_queue<pair<int,pair<int,string>>> q;
	q.push({0,{0,"0"}});
	vis[0][0] = at;
	dp[0][0] = 0;
	ll ans = 1e9;
	while(q.size()){
		ll cst = -q.top().first;
		int curE = q.top().second.first;
		string cur = q.top().second.second;
		q.pop();
		if(e == curE){
			ans = min(ans , cst + (ll)cur.size());
			continue;
		}
		if(cst > dp[curE][stoll(cur)])continue;

		string to;
		for(int j=0;j<w;j++){
			if(g[curE][j] == 0)continue;
			to += string(g[curE][j] , char('1' + j ));
		}
		// cerr << cst << ' ' << curE << ' ' << cur << ' ' << to << '\n';

		do{

			int cost = cst + cur.size() + to.size();
			for(int i=0;i<min(to.size() , cur.size());i++){
				if(to[i] == cur[i])cost-=2;
				else break;
			}

			ll val = stoll(to);

			if(cost >= dp[curE + 1][val] && vis[curE + 1][val] == at)continue;
			vis[curE + 1][val] = at;
			dp[curE + 1][val] = cost;
			// cerr << curE << ' ' << val << ' ' << cost << '\n';
			q.push({-cost , {curE + 1, to}});

		}while(next_permutation(all(to)));
	}

	cout << ans - 1 << '\n';
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