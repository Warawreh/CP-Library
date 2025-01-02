#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU{

   vector<int> dsu,sz,rnk;

   void init(int n,int x){
      dsu = sz = rnk = vector<int> (n+x);
      iota(dsu.begin()+x,dsu.end(),x);
      fill(sz.begin(),sz.end(),1);
   }

   int find(int u){
      return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
   }

   bool merge(int u,int v){
      u = find(u);
      v = find(v);
      if(u == v)return false;
      if(sz[u] < sz[v])swap(u,v);
      // if(rnk[u] > rnk[v])swap(u,v);
      sz[u] += sz[v];
      // rnk[v] = rnk[u] + 1;
      dsu[v] = u;
      return true;
   }   
};


int n,k;
vector<int> a;
DSU d;
int mx = 10;
vector<bool> vis;

void dfs(int u,int p){
	if(vis[u])return;
	if(d.sz[d.find(u)] + d.sz[d.find(p)] >= mx)return;
	vis[u] = 1;
	d.merge(u, p);
	dfs(a[u] , p);
}

void solve(){
	while(1){
		a.clear();
		a.resize(n);
		d.init(n,0);
		vis.clear();
		vis.resize(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]--;
		}
		for(int i=0;i<n;i++){
			if(!vis[i]){
				dfs(i,i);
			}
		}
		vector<int> c(n);
		for(int i=0;i<n;i++)cout << d.find(i) + 1 << ' ';
		cout << endl;
		fflush(stdout);	
		int res = 0;
		cin>>res;
		if(res == -1)exit(0);
		else if(res == 1)break;

	}
}

int main(){
	fast
	int t;
	cin>>t>>n>>k;
	for(int T=1;T<=t;T++){
		solve();
	}
}

/*
python run.py python3 tt.py3 0 -- a.exe	
*/