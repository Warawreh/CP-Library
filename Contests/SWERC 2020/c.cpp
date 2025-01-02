#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld eps = 1e-8;

struct DSU{

   vector<int> dsu,sz,rnk;
   vector<vector<ld>> borders;

   void init(int n,int x){
      dsu = sz = rnk = vector<int> (n+x);
      borders.resize(n+x);
      iota(dsu.begin()+x,dsu.end(),x);
      fill(sz.begin(),sz.end(),1);
   }

   int find(int u){
      return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
   }

    void set(int u,vector<ld> v){
    	borders[u] = v;
    }

   bool merge(int u,int v){
      u = find(u);
      v = find(v);
      if(u == v)return false;
      if(sz[u] < sz[v])swap(u,v);
      sz[u] += sz[v];

      // assert(borders[u].size() == 4 && borders[v].size() == 4);
      borders[u][0] = min(borders[u][0] , borders[v][0]);
      borders[u][1] = max(borders[u][1] , borders[v][1]);
      borders[u][2] = min(borders[u][2] , borders[v][2]);
      borders[u][3] = max(borders[u][3] , borders[v][3]);

      dsu[v] = u;
      return true;
   }   
};

inline ld S(ld a){return a*a;}

int main(){
    fast
    int x,y;
    int n;
    cin>>x>>y>>n;
    vector<pair<ld,ld>> p(n);
    for(int i=0;i<n;i++)cin>>p[i].first>>p[i].second;
    ld lo = 0,hi = 1e6;
	for(int it=0;it<=50;it++){
		if(hi - lo <= eps)break;
		ld md = (lo + hi)/2;
		DSU d;
		d.init(n , 0);


		bool can = true;
		for(int i=0;i<n;i++){
			if(S(p[i].first) + S(p[i].second) <= S(md)){
				can = false;
				break;
			}

			d.set(i,{p[i].first - md, p[i].first + md, p[i].second - md,p[i].second + md});

			for(int j=0;j<i;j++){
				if(d.find(i) == d.find(j))continue;

				if(S(p[i].first - p[j].first) + S(p[i].second - p[j].second) <= 4 * S(md)){
					d.merge(i, j);
				}
			}

		}

		if(can){
			for(int i=0;i<n;i++){
				vector<ld> &cur = d.borders[d.find(i)];
				if((cur[0] <= 0 && cur[1] >= x) || (cur[2] <= 0 && cur[3] >= y)){
					can = false;
					break;
				}
				if((cur[0] <= 0 && cur[2] <= 0) || (cur[1] >= x && cur[3] >= y)){
					can = false;
					break;	
				}
			}
		}
		// cerr << setprecision(5) << fixed << it << ' ' << md << ' ' << can << '\n';

		if(!can){
			hi = md;
		}else lo = md;
	}
	cout << setprecision(6) << fixed << lo << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/