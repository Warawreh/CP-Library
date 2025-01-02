#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> f,rem,per,pp;
vector<int> sz;
vector<int> hds;
vector<vector<pair<int,int>>> g;
int hd;
vector<int> bad;
map<pair<int,int> , int> id;

void dfs(int u,int p){
	if (clock() > 0.95*CLOCKS_PER_SEC) {
	    cout<<"No\n";
	    exit(0);
	  }
	sz[u] = 1;
	if(p == -1)per[u] = u;
	else per[u] = per[p];
	pp[u] = p;
	// cerr << u << ' ' << p << ' ' << per[u] << '\n';
	for(pair<int,int> a : g[u]){
		int v = a.first;
		int x = a.second;
		if(v == p || bad[x])continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

int main(){
	fast
	int n;
	cin>>n;
	f = {1,1};
	vector<int> good(n + 1);
	good[1] = 1;
	for(int i=2;;i++){
		int nxt = f[i-1] + f[i-2];
		if(nxt > n)break;
		good[nxt] = 1;
		// cout << nxt << '\n';
		f.push_back(nxt);
	}
	if(n != f.back()){
		cout << "No\n";
		return 0;
	}
	sz = pp = bad = per = rem = vector<int>(n);
	vector<int> in(n);
	g.resize(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		// u = i+1;
		// v = i+2;
		u--;v--;
		id[{u,v}] = id[{v,u}] = i;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
		in[u]++;
		in[v]++;
	}
	bool can = true;
	for(int i=0;i<n;i++){
		int x = 0;
		for(pair<int,int> a : g[i]){
			int v = a.first;
			if(in[v] == 1)x++;
		}
		if(x >= 3)can = false;
	}
	if(can){
		hds.push_back(0);
		rem[0] = 1;
		while(hds.size() < n){
			for(int i : hds){
				// cerr << i << ' ';
				dfs(i,-1);
			}
			// cerr << '\n';
			// cerr << hds.size() << '\n';
			int tmp = hds.size();
			for(int i=0;i<n;i++){
				// cerr << sz[i] << ' ';
				if(sz[per[i]] == -1)continue;
				if(good[sz[i]] && good[sz[per[i]] - sz[i]]){
					// cerr << i << ' ' << per[i] << ' ' << sz[i] << ' ' << sz[per[i]] << '\n';
					rem[i] = 1;
					sz[per[i]] = -1;
					sz[i] = -1;
					bad[id[{i,pp[i]}]] = 1;
					hds.push_back(i);
				}
			}
			if(hds.empty())break;
			// cerr << '\n';
			for(int i : hds){
				// cerr << i << ' ' << sz[i] << '\n';
				if(sz[i] != -1 && sz[i] != 1){
					cout << "No\n";
					return 0;	
				}
			}
			if(tmp == hds.size()){
				cout << "No\n";
				return 0;
			}
			// cerr << "________________\n";
		}
		cout << "Yes\n";
	}else cout << "No\n";

}