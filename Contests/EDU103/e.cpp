#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

unordered_map<string,vector<int>> f;
unordered_map<string,int> id;

int main(){
	fast
	int n,m,k;
	cin>>n>>m>>k;
	vector<string> p(n);
	int ID = 0;
	vector<string> dist;
	for(int i=0;i<n;i++){
		cin>>p[i];
		if(f[p[i]].size() == 0){
			id[p[i]] = ++ID;
			dist.push_back(p[i]);
		}
		f[p[i]].push_back(i);
	}
	vector<vector<int>> g(ID+1);
	vector<int> in(ID+1);
	queue<int> q;
	for(int i=0;i<m;i++){
		string a;
		int at;
		cin>>a>>at;
		at--;
		for(int j=0;j<k;j++){
			if(p[at][j] == '_')continue;
			if(p[at][j] != a[j]){
				cout << "NO\n";
				return 0;
			}
		}
		for(int mk=0;mk<(1<<k);mk++){
			string cur = a;
			for(int j=0;j<k;j++){
				if((mk >> j) & 1)cur[j] = '_';
			}
			if(cur == p[at])continue;
			if(id[cur] == 0)continue;
			g[id[p[at]]].push_back(id[cur]);
			in[id[cur]]++;
		}
	}
	for(int i=1;i<=ID;i++){
		if(!in[i]){
			q.push(i);
		}
	}
	vector<int> ans;
	while(q.size()){
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for(int v : g[u]){
			// cerr << u << ' ' << v << '\n';
			in[v]--;
			if(!in[v]){
				q.push(v);
			}
		}
	}
	// cerr << ans.size() << ' ' << ID << '\n';
	if(ans.size() == ID){
		cout << "YES\n";
		for(int i : ans){
			for(int x : f[dist[i-1]])
				cout << x + 1 << ' ';
		}
		cout << '\n';
	}else cout << "NO\n";
}