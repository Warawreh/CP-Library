#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g,g2;
vector<int> bad;
int b;
vector<int> deg;

void dfs(int u){
	bad[u] |= (1 << b);
	for(int v : g[u])dfs(v);
}

void solve(){
	int n;
	cin>>n;
	g.clear();
	g.resize(n);
	g2.clear();
	g2.resize(n);
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		l--;
		g2[i].push_back(l);
	}
	for(int i=0;i<n;i++){
		int r;
		cin>>r;
		r--;
		g2[i].push_back(r);
	}


	bool can = true;
	for(int u=0;u<n;u++){
		for(int v : g2[u]){
			for(int w : g2[v]){
				if(w == u)can = false;
			}
		}
	}
	if(!can){
		cout << "IMPOSSIBLE\n";
		return;
	}

	auto addEdge = [&](int u,int v){
		g[u].push_back(v);
		g[v].push_back(u);
		return;
	};

	for(int i=0;i<n;i++){
		addEdge(i , g2[i][0]);
		addEdge(i , g2[g2[i][0]][0]);
		addEdge(i , g2[g2[i][0]][1]);
		addEdge(i , g2[i][1]);
		addEdge(i , g2[g2[i][1]][0]);
		addEdge(i , g2[g2[i][1]][1]);
	}

	for(int i=0;i<n;i++){
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
	}

	string val = "ACDEHIJKMORST";
	bad = vector<int>(n , 0);
	string ans(n,'X');
	for(int i=0;i<val.size();i++){
		b = i;
		for(int u=0;u<n;u++){
			if(ans[u] != 'X')continue;

			for(int v : g[u]){
				if(ans[v] == val[i])bad[u] |= (1 << i);
			}

			if((bad[u] >> i) & 1)continue;

			ans[u] = val[i];
			dfs(u);

		}
	}
	for(int i=0;i<n;i++){
		if(ans[i] == 'X'){
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	cout << ans << '\n';
	for(int u=0;u<n;u++){
		for(int v : g[u]){
			if(ans[u] == ans[v]){
				cerr << "u -> v : " << u << ' ' << v << '\n';
				assert(0);
			}
		}
	}
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