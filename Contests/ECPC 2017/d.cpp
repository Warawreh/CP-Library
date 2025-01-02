#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5 + 10;

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


void solve(){
	int n;
	cin>>n;
	vector<int> hv(nax,-1);
	DSU d;
	d.init(n,0);

	ll ans = 0;

	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(hv[a] == -1)hv[a] = i;
		else{
			ans += a;
		}
	}

	for(int i=nax-1;i>=1;i--){
		int lst = -1;
		for(int j=i;j<nax;j+=i){
			if(hv[j] == -1)continue;
			if(lst == -1)lst = hv[j];
			
			if(d.find(hv[j]) != d.find(lst)){
				ans += i;
				d.merge(hv[j] , lst);
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	fast
	freopen("dream.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ": ";
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/