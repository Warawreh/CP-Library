#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void NO(){
	cout << "0\n";
	exit(0);
}

vector<vector<int>> l;
vector<int> gid,gh,pen,in,val,r;
int id;
int n,k;

void dfs(int u,int p){
	gid[u] = id;
	pen[id] += in[u];
	val[u] = in[u];
	for(int v : l[u]){
		if(gid[v] == 0)dfs(v,u);
	}
}

vector<int> w;
void get(int u,int p){
	w.push_back(u);
	for(int v : l[u]){
		if(p != v)get(v,u);
	}
}


int main(){
	fast
	cin>>n>>k;
	r = val = in = pen = gh = gid = vector<int>(n + 1,0);
	l.resize(n + 1);
	vector<bool> sin(n),sout(n);
	queue<int> q;
	vector<vector<int>> g(n + 1);
	vector<int> par(n);

	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		p--;
		if(p != -1){
			in[i] = 1;
			g[p].push_back(i);
			par[i] = p;
		}else{
			q.push(i);
		}
	}

	for(int i=0;i<k;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		if(par[u] == v)NO();
		if(sin[v] || sout[u])NO();
		bool have = false;
		for(int x : g[u])
			if(x == v)
				have = true;
		if(!have){
			g[u].push_back(v);
			in[v]++;
		}
		l[u].push_back(v);
		sin[v] = 1;
		sout[u] = 1;
	}
	
	for(int i=0;i<n;i++){
		if(sout[i] == 1 && sin[i] == 0){
			id++;
			gh[id] = i;
			dfs(i,-1);
		}
	}

	for(int u=0;u<n;u++){
		for(int v : g[u]){
			if(gid[u] == gid[v]){
				val[v]--;
				in[v]--;
				pen[gid[u]]--;
			}
		}
	}
	// return 0;
	vector<int> ans;
	vector<bool> vis(n + 1);
	assert(q.size());
	int u = q.front();
	// cerr << u << '\n';
	w.clear();
	get(u,-1);
	for(int v : w){
		if(in[v])NO();
		vis[v] = 1;
		if(v == u)continue;
		q.push(v);
	}

	if(k != n-1){
		while(q.size()){
			int u = q.front();
			// cerr << "at : " << u << '\n';
			q.pop();
			ans.push_back(u);
			for(int v : g[u]){
				// cerr << v << ' ' << gid[v] << ' ' [v] << ' ' << pen[gid[v]] << ' ' << vis[v] << '\n';
				if(gid[v] == 0){
					if(vis[v])NO();
					vis[v] = 1;
					q.push(v);
				}else if(r[gid[v]] != 2){
					if(v == gh[gid[v]] && r[gid[v]] == 0)
						r[gid[v]] = 1;
					// cerr << ' ' << u << ' ' << v << ' ' << val[v] << ' ' << pen[gid[v]] << '\n';
					pen[gid[v]] -= val[v];
					val[v] = 0;
					if(pen[gid[v]] == 0 && r[gid[v]] == 1){
						r[gid[v]] = 2;
						w.clear();
						get(gh[gid[v]],-1);
						// cerr << ' ' << gh[gid[v]] << '\n';
						for(int x : w){
							if(vis[x])NO();
							// assert(!vis[x]);
							vis[x] = 1;
							// cerr << x << '\n';
							q.push(x);
						}
					}
					// cerr << pen[gid[v]] << ' ' << val[v] << '\n';
				}
			}
		}

	}else{
		while(q.size()){
			int u = q.front();
			q.pop();
			ans.push_back(u);
		}
	}
	if(ans.size() != n)NO();
	else{
		for(int i : ans)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}