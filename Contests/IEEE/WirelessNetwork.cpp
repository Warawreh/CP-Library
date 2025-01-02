#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<string,int> mp;
int at;

int get(string &s){
	if(mp[s] == 0)mp[s] = ++at;
	return mp[s];
}

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


int main(){
    fast
    int m;
    cin>>m;
    at = 0;
    vector<int> sp;

    vector<vector<int>> e;
    for(int i=0;i<m;i++){
    	string a,b;
    	int w,h;
    	cin>>a>>b>>w>>h;

    	int u = get(a);
    	int v = get(b);
    	u--;v--;
    	// cerr << a << ' ' << b << ' ' << w << ' ' << h << ' ' << u << ' ' << v << '\n';

    	if(h){
    		sp.push_back(u);
    		sp.push_back(v);
    	}
    	e.push_back({u,v,w,h});
    }

    sort(all(sp));
	sp.resize(unique(all(sp)) - sp.begin());

	int n = sp.size();
	ll ans = 1e18;

	vector<bool> s(at);

	// for(int u : sp)
	// 	cerr << u << ' ';
	// cerr << '\n';

	for(int mask=0;mask<(1 << n);mask++){
		ll cur = 0;

		DSU d;
		d.init(at,0);

		for(int i=0;i<n;i++){
			if((mask >> i) & 1){
				s[sp[i]] = 1;
				cur += 1e4;
			}
		}

		vector<pair<int,pair<int,int>>> edgs;

		for(vector<int> c : e){
			int u = c[0];
			int v = c[1];
			int w = c[2];
			int h = c[3];
			if(h && !s[u] && !s[v])continue;
			// if(mask == 8)cerr << u << ' ' << v << ' ' << w << ' ' << h << '\n';
			edgs.push_back({w,{u,v}});
		}
		sort(all(edgs));

		for(int i=0;i<edgs.size();i++){
			int u = edgs[i].second.first;
			int v = edgs[i].second.second;
			int w = edgs[i].first;
			if(d.find(u) == d.find(v))continue;
			cur += w;
			d.merge(u,v);
		}

		bool good = true;
		for(int i=0;i<at;i++)
			if(d.find(i) != d.find(0))
				good = false;

		if(good)
			ans = min(ans , cur);	

		for(int i=0;i<n;i++){
			if((mask >> i) & 1){
				s[sp[i]] = 0;
			}
		}

	}
	cout << ans << '\n';

}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/