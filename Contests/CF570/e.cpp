#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<string,int> cost;

int main(){
	fast
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	queue<string> q;
	q.push(s);
	cost[s] = 0;
	ll ans = 0;
	while(q.size()){
		string u = q.front();
		k--;
		ans += cost[u];
		q.pop();
		if(!k)break;
		int n = u.size();
		for(int i=0;i<n;i++){
			string nxt = u;
			nxt.erase(nxt.begin() + i);
			if(cost.count(nxt))continue;
			cost[nxt] = cost[u] + 1;
			// cerr << nxt << ' ' << cost[nxt] << '\n';
			q.push(nxt);
		}
	}
	if(k)ans = -1;
	cout << ans << '\n';
}