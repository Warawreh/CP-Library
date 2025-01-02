#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;

const int mod = 1e9+7;

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res) % mod;
	if(b%2)res = (res * a)%mod;
	return res;
}

vector<int> dsu,sz,rnk,good;
vector<vector<pair<int,int>>> cmp;

void init(int n,int x){
	dsu = sz = rnk = vector<int> (n+x);
	iota(dsu.begin()+x,dsu.end(),x);
	fill(sz.begin(),sz.end(),1);
	cmp.resize(n + 1);
	// for(int i=0;i<n;i++)cmp[i].push_back(i);
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
	if(cmp[u].size() < cmp[v].size())swap(cmp[u],cmp[v]);
	for(auto x : cmp[v])cmp[u].push_back(x);
	cmp[v].clear();
	sz[u] += sz[v];
	rnk[v] = rnk[u] + 1;
	dsu[v] = u;
}

int main(){
	fast
	int n,m;
	cin>>n>>m;
	g.resize(m);
	set<pair<int,int>> st;
	vector<int> ans,hv(m);
	init(m+1,0);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		if(k == 1){
			int a;
			cin>>a;
			a--;
			if(hv[a])continue;
			// cerr << a << ' ' << cmp[find(a)].size() << '\n';
			for(auto v : cmp[find(a)]){
				st.erase({min(v.first,v.second),max(v.first,v.second)});
				hv[v.first] = hv[v.second] = 1;
			}
			cmp[find(a)].clear();
			hv[a] = 1;
			ans.push_back(i);
		}else{
			int a,b;
			cin>>a>>b;
			if(a > b)swap(a,b);
			a--;b--;
			if(hv[a] && hv[b])continue;
			if(find(a) == find(b))continue;
			merge(a,b);
			cmp[find(a)].push_back({a,b});
			
			if(hv[a] || hv[b]){
				hv[b] = hv[a] = 1;
				for(auto v : cmp[find(a)]){
					st.erase({min(v.first,v.second),max(v.first,v.second)});
					hv[v.first] = hv[v.second] = 1;
				}
				cmp[find(a)].clear();
			}else{
				st.insert({a,b});
			}
			ans.push_back(i);
		}
	}
	int p = st.size();
	for(int i=0;i<m;i++)p+=hv[i];
	cout << Pow(2,p) << ' ' << ans.size() << '\n';
	for(int x : ans)
		cout << x+1 << ' ';
}