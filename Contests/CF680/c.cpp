#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> id,c,cid,ct;
vector<vector<int>> g;
vector<bool> good;
int T;

void dfs(int u){
	cid[u] = T;
	for(int v : g[u]){
		if(c[v] == c[u]){
			good[id[u]] = false;
		}else{
			if(c[v] == -1){
				c[v] = !c[u];
				dfs(v);
			}
		}
	}
}

vector<int> dsu,sz,rnk;

void init(int n,int x){
	dsu = sz = vector<int> (n+x);
	iota(dsu.begin()+x,dsu.end(),x);
	fill(sz.begin(),sz.end(),1);
}

int find(int u){
	return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
}

void merge(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[u] < sz[v])swap(u,v); // enable for fast dsu
	// if(rnk[u] > rnk[v])swap(u,v);
	sz[u] += sz[v];
	dsu[v] = u;
}

int main(){
	fast
	int n,m,k;
	cin>>n>>m>>k;
	ll ans = k * 1LL * (k-1) / 2;
	{
		id.resize(n);
		g.resize(n);
		c.resize(n,-1);
		good.resize(k , true);
		cid.resize(n);
	}
	for(int i=0;i<n;i++){
		cin>>id[i];
		id[i]--;
	}

	vector<vector<int>> e;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		if(id[u] == id[v]){
			g[u].push_back(v);
			g[v].push_back(u);
		}else{
			if(id[u] > id[v])swap(u,v);	
			e.push_back({id[u] , id[v] , u , v});
		}
	}
	sort(all(e) , [&] (vector<int> a ,vector<int> b){
		if(make_pair(a[0] , a[1]) == make_pair(b[0] , b[1])){
			return make_pair(cid[a[2]] , cid[a[3]]) < make_pair(cid[b[2]] , cid[b[3]]);
		}
		return make_pair(a[0] , a[1]) < make_pair(b[0] , b[1]);
	});
	for(int i=0;i<n;i++){
		if(c[i] == -1){
			T++;
			c[i] = 0;
			dfs(i);
		}
	}
	ct.resize(T + 1,-1);
	int g = 0;
	for(int i=0;i<k;i++){
		if(good[i] == false){
			ans -= (k - 1 - g);
			g++;
		}
	}
	// cerr << good[i] << '\n';


	int l = 0;
	bool isgood = true;
	vector<vector<int>> tmp;
	vector<int> t;
	for(int i=0;i<e.size();i++){
		if(i && (e[i][0] != e[i-1][0] || e[i][1] != e[i-1][1])){
			// cerr << e[i][0] << ' ' << e[i][1] << '\n';
			sort(all(t));
			t.resize(unique(all(t)) - t.begin());
			init(t.size() * 2 , 0);

			for(vector<int> a : tmp){
				int id1 = lower_bound(all(t) , a[0]) - t.begin();
				int id2 = lower_bound(all(t) , a[1]) - t.begin();
				assert(id1 < t.size());
				assert(id2 < t.size());
				if(a[2] == 0){
					merge(id1 , id2 + t.size());
					merge(id1 + t.size() , id2);
				}else{
					merge(id1 + t.size() , id2 + t.size());
					merge(id1 , id2);
				}
			}	
			for(int j=0;j<t.size();j++){
				if(find(j) == find(j + t.size()))isgood = false;
			}

			if(!isgood && good[e[i-1][0]] == true && good[e[i-1][1]] == true)ans--;
			t.clear();
			tmp.clear();
			isgood = true;
		}
		int u = e[i][2];
		int v = e[i][3];
		t.push_back(cid[u]);
		t.push_back(cid[v]);
		tmp.push_back({cid[u],cid[v],!(c[u] == c[v])});
	}
	sort(all(t));
	t.resize(unique(all(t)) - t.begin());
	init(t.size() * 2 , 0);

	for(vector<int> a : tmp){
		int id1 = lower_bound(all(t) , a[0]) - t.begin();
		int id2 = lower_bound(all(t) , a[1]) - t.begin();
		if(a[2] == 0){
			merge(id1 , id2 + t.size());
			merge(id1 + t.size() , id2);
		}else{
			merge(id1 + t.size() , id2 + t.size());
			merge(id1 , id2);
		}
	}	
	for(int j=0;j<t.size();j++){
		if(find(j) == find(j + t.size()))isgood = false;
	}

	if(e.size() && !isgood && good[e[e.size() - 1][0]] == true && good[e[e.size() - 1][1]] == true)ans--;
	cout << ans << '\n';
}
