#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;

struct sat{
	vector<vector<int>> g;
	vector<int> idx,gid,gh,low,s;
	vector<bool> vis;
	int m,DFS,cmp;

	void init(int M){
		m = M;
		g.clear();
		g.resize(m);
		idx = gid = gh = low = vector<int>(m);
		s.clear();
		vis = vector<bool>(m);
		DFS = cmp = 0;
	}
	 
	void dfs(int u){
		idx[u] = low[u] = ++DFS;
		s.push_back(u);
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i];
			if(!idx[v])dfs(v);
			if(vis[v])low[u] = min(low[u],low[v]);
		}
		if(low[u] == idx[u]){
			gh[cmp] = u;
			while(1){
				int v = s.back();
				s.pop_back();
				vis[v] = 0;
				gid[v] = cmp;
				// cerr << v << ' ' << cmp << '\n';
				if(v==u)break;
			}
			cmp++;
		}
	}
	 
	int NOT(int x){
		if(x >= m)return x-m;
		return x+m;
	}

	void addEdge(int u,int v){
		g[u].push_back(v);
		// g[NOT(u)].push_back(v);
		// g[NOT(v)].push_back(u);
	}
};

 
string tmp = "ATGC";
int getId(char c){
	for(int i=0;i<4;i++){
		if(c == tmp[i])return i;
	}
}

int getDist(char a,char b){
	int v1=getId(a),v2=getId(b);
	if(v1 > v2)swap(v1,v2);
	return min(v2 - v1 , v1+n-v2);
}

int main(){
	fast
	while(1){
		int t;
		cin>>n>>t;
		if(!n && !t)break;
		m = n*2;
		init();

		string s;
		cin>>s;

		for(int i=0;i<n;i++){
			// g[i].push_back(NOT(i+1));
			// g[i+1].push_back(NOT(i));
			if(i+1<n)
				addEdge((i) , NOT(i+1));

			if(i){
				addEdge((i) , NOT(i-1));
			}
			// addEdge(NOT(i),NOT(i+1));
		}

		bool can = true;
		sat x,y;
		x.init(m);
		y.init(m);

		for(int i=0;i<t;i++){
			string k;
			cin>>k;
			k.pop_back();
			int p = stoi(k);
			vector<int> cur(p);
			for(int j=0;j<p;j++){
				cin>>cur[i];
			}

			for(int j=0;j<p/2;j++){
				char l = s[cur[j]];
				char r = s[cur[p-1-j]];

				if(l == r)continue;
				int dist = getDist(l,r);

				if(dist == 0){
					addEdge(cur[j],cur[p-1-j]);
					// addEdge(NOT(cur[j]),NOT(cur[p-1-j]));
				}else if(dist == 1){
					addEdge(cur[j],NOT(cur[p-1-j]));
					addEdge(NOT(cur[j]),cur[p-1-j]);
				}else if(dist == 2){
					
				}else assert(0);
			}
		}
		for(int i=0;i<n + n;i++)
			if(!idx[i])
				dfs(i);
		for(int i=0;i<n;i++){
			if(gid[i] == gid[NOT(i)]){
				can = false;
				break;
			}
		}

		cout << (can ? "YES\n" : "NO\n");

	}
	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/