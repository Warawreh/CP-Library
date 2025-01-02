#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> in(n);
	vector<bool> good(n,true);
	vector<unordered_set<int>> E(n + 1);
	vector<vector<int>> g(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
		if(u > v)swap(u,v);
		E[u].insert(v);
		in[u]++;
		in[v]++;
	}
	for(int i=0;i<n;i++)sort(all(g[i]));
	if(k*1LL*(k - 1)/2 > m){
		cout << -1 << '\n';
		return;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(in[i] < k){
			q.push(i);
		}
	}
	while(q.size()){
		int u = q.front();
		good[u] = false;
		q.pop();
		// cerr << "HE : " << u << '\n';
		for(int v : g[u]){
			if(in[v] == k){
				q.push(v);
			}
			in[v]--;
		}
		if(in[u] == k-1){
			// cerr << u << '\n';
			bool Good = true;
			vector<int> s;
			for(int x : g[u]){
				if(!good[x])continue;
				s.push_back(x);
			}
			assert(s.size() == k-1);
			for(int i=0;i<s.size();i++){
				for(int j=i+1;j<s.size();j++){
					if(E[s[i]].find(s[j]) == E[s[i]].end()) {
						Good = false;
						break;
					}
				}
			}
			// cerr << Good << ' ' << cnt << '\n';
			if(Good){
				cout << 2 << '\n';
				cout << u+1 << ' ';
				for(int x : g[u]){
					if(!good[x])continue;
					cout << x + 1 << ' ';
				}
				cout << '\n';
				return;
			}
		}
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(good[i])ans.push_back(i);
	}
	if(ans.size()){
		cout << 1 << ' ' << ans.size() << '\n';
		for(int i : ans)
			cout << i+1 << ' ';
		cout << '\n';
	}else{
		cout << -1 << '\n';
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}