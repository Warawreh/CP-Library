#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2e5;
int take = 500;
const int want_sz = 250;

vector<int> g[nax],gsz;
int in[nax];
double V,E;
vector<int> gid;
vector<vector<int>> com;

ld find_ein(vector<int> c){
	int ein = 0;
	for(int u : c){
		for(int v : g[u]){
			ein += (gid[u] == gid[v]);
		}
	}
	return ein;
}

ld find_eout(vector<int> c){
	int eout = 0;
	for(int u : c){
		for(int v : g[u]){
			eout += (gid[u] != gid[v]);
		}
	}
	return eout;
}

ld den(vector<int> c){
	if(c.size() == 1)return 1.0;
	ld ein = find_ein(c);
	
	ld n = c.size();
	return (ein*2.0) / (n * (n-1));
}

ld reg(){
	ld n = com.size();
	ld res = 0;
	for(vector<int> c : com){
		res += den(c);
	}
	res = res * (1/n);
	res = res - (1.0 / (V/n));	
	return res*0.5;
}

ld S(ld a){return a*a;}

ld mod(){
	ld res = 0;
	for(vector<int> c : com){
		ld cur = find_ein(c)/(E + 0.0);
		res = cur - S( (2*find_ein(c) + find_eout(c)) / (2.0 * E) );
	}
	return res;
}

ld calc_cost(){
	return reg() + mod();
}

int main(){
	fast
	freopen("icpc/a1.in","r",stdin);
	freopen("icpc/a1.out","w",stdout);
	int n = 0;

	{//Read input
		int u,v;
		while(cin >> u >> v){
			n = max(n , max(u,v));
			g[u].push_back(v);
			g[v].push_back(u);
			in[u]++;
			in[v]++;
			E++;
		}
		n++;
		V = n;
	}

	//Testing
	{
		vector<int> id(n);
		iota(all(id) , 0);
		sort(all(id) , [&](int a,int b){
			return g[a].size() > g[b].size();
		});
		// int cnt = 0;
		// for(int i=0;i<100;i++)cerr << g[id[i]].size() << ' ';
		// cerr << '\n';
	}
	// cerr << cnt << '\n';

	//Solution
	queue<int> q;
	gid.resize(n,-1);
	vector<bool> vis(n,false);
	//
	int id = 0;
	while(1){
		com.push_back({});
		gsz.push_back(0);
		bool done = true;
		for(int i=0;i<n;i++){
			if(g[i].size() >= take && gid[i] == -1 && vis[i] == false){
				q.push(i);
				vis[i] = 1;
				gid[i] = id;
				gsz[id]++;
				com[id].push_back(i);
			}
			if(gid[i] == -1)done = false;
		}
		id++;
		if(done)break;

		while(q.size()){
			int u = q.front();
			// if(gid[u] == -1){
			// 	gid[u] = id++;
			// 	gsz.push_back(1);
			// 	com.push_back({});
			// }
			// com[gid[u]].push_back(u);
			q.pop();
			for(int v : g[u]){
				in[v]--;
				if(g[v].size() < g[u].size() * 0.00015)continue;
				if(gsz[gid[u]] >= want_sz)continue;
				if(gid[v] == -1){
					gid[v] = gid[u];
				}
				if(vis[v])continue;
				gsz[gid[v]]++;
				com[gid[v]].push_back(v);

				vis[v] = true;
				q.push(v);
			}
		}
		take -= 100;
	}
	for(int i=0;i<n;i++){
		assert(gid[i] != -1);
		// if(com[gid[i]].size() > want_sz)cerr << gid[i] << ' ' << com[gid[i]].size() << '\n';
		// assert(com[gid[i]].size() <= want_sz);
	}
	//Print
	cerr << setprecision(3) << fixed << (calc_cost() + 1.0) * 1e5 << '\n';

	for(vector<int> a : com){
		// assert(a.size());
		if(a.empty())continue;
		for(int i =0;i<a.size();i++){
			if(i)cout << ' ';
			cout << a[i];
		}
		cout << '\n';
	}
}