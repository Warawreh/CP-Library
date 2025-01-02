#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5 + 10;

vector<int> sz;
vector<bool> isCentroid;
int n;
vector<vector<pair<int,int>>> g;


vector<int> prime;
vector<bool> is_composite;
vector<int> hv;
ll ans;

void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

void dfs(int u,int p){
   sz[u] = 1;
   for(auto &[v,d] : g[u]){
      if(v == p || isCentroid[v])continue;
      dfs(v,u);
      sz[u] += sz[v];
   }
}

vector<int> add;
vector<int> f;
ll all;

void go1(int u,int p,int val,int prime = 0){
	if(val > 2)return;

	if(val == 2)ans++;
	else if(val == 1){
		add.push_back(prime);
		ans += all - f[prime];
	}

   for(auto &[v,d] : g[u]){
      if(v == p || isCentroid[v])continue;

      if(hv[d] && prime == d)continue;
      go1(v , u , val + hv[d] , max(prime , d));

   }

}

void decompose(int u){
   dfs(u,-1);
   int lst = -1,groupSize = sz[u];

   while(true){
      int nxt = -1;
      for(auto &[v,d] : g[u]){
         if(v == lst || isCentroid[v])continue;
         if(sz[v] * 2 > groupSize){//True at most once
            nxt = v;
            break;
         }
      }
      if(nxt == -1)break;
      lst = u;
      u = nxt;
   }

   isCentroid[u] = true;

   all = 0;

   vector<int> rem;
   for(auto &[v,d] : g[u]){
      if(isCentroid[v])continue;
      go1(v,u,hv[d],d);
      
      for(int val : add){
      	f[val]++;
      	rem.push_back(val);
      	all++;
      }
      add.clear();
   }

   for(int val : rem)f[val]--;
   	rem.clear();

   for(auto &[v,d] : g[u]){
      if(isCentroid[v])continue;
      decompose(v);
   }
}



void solve(){
	cin>>n;

	{
		g.clear();
		g.resize(n);
		sz = vector<int>(n,0);

		isCentroid = vector<bool>(n,0);
		ans = 0;
	}

	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	decompose(0);

	cout << ans << '\n';
}

int main(){
	fast
	freopen("evaluations.in","r",stdin);

	sieve(nax);
	hv = vector<int>(nax);
	f = vector<int>(nax , 0);
	hv[1] = 0;

	for(int i=2;i<nax;i++){
		int tmp = i;
		for(int p : prime){
			if(p > tmp)break;
			int cnt = 0;
			while(tmp % p == 0){
				tmp /= p;
				cnt++;
			}
			if(cnt == 1)hv[i]++;
			else if(cnt > 1)hv[i] += 3;
		}
	}

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