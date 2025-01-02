#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct SegTree{
    typedef ll T;
    int n;
    vector<T> seg,lazy;
    const T oo = 0;

    SegTree(){

    }

    SegTree(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n,0);
    }

    void init(int _n){
    	n = _n;
        seg = lazy = vector<T>(4*n,0);
    }

    void pro(int n,int s,int e){
    	if(!lazy[n])return;
        seg[n] = lazy[n];
        if(s != e){
            lazy[n+n] = lazy[n];
            lazy[n+n+1] = lazy[n];
        }
        lazy[n] = 0;
    }

    void update(int l,int r,T val,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] = val;
            pro(n,s,e);
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = max(seg[n+n] , seg[n+n+1]);
    }

    T get(int l,int r,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return oo;
        if(s >= l && e <= r){
            return seg[n];
        }
        return max(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
    }

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};



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
	int n;
	cin>>n;

	const int nax = 1002;
	vector<SegTree> r(nax),c(nax);
	for(int i=0;i<nax;i++){
		r[i].init(nax);
		c[i].init(nax);
	}

	int x=-1,y=-1;
	cin>>x>>y;
	for(int i=0;i<n;i++){
		int nx,ny;
		cin>>nx>>ny;

		// cerr << x << ' ' << y << ' ' << nx << ' ' << ny << '\n';
		if(x == nx){
			r[x].update(min(y , ny) , max(y , ny) - 1 , 1);
		}else{
			c[y-1].update(min(x , nx) , max(x , nx) - 1 , 1);
		}

		x = nx;
		y = ny;
	}

	vector<vector<bool>> up(nax,vector<bool>(nax)),right(nax,vector<bool>(nax));
	for(int i=0;i<nax;i++){
		for(int j=0;j<nax;j++){
			up[i][j] = r[i].get(j,j);
			right[i][j] = c[j].get(i,i);
		}
	}

	// for(int i=0;i<nax;i++){
	// 	for(int j=0;j<nax;j++){
	// 		cerr << up[i][j] << " \n"[j == nax-1];
	// 	}
	// }
	// cerr << '\n';
	// for(int i=0;i<nax;i++){
	// 	for(int j=0;j<nax;j++){
	// 		cerr << right[i][j] << " \n"[j == nax-1];
	// 	}
	// }

	vector<vector<bool>> vis(nax,vector<bool>(nax,0));
	{//bfs from 0,0
		vector<pair<int,int>> q;
		q.push_back({0,0});
		vis[0][0] = 1;

		int cnt = 0;
		// cerr << 1 << '\n';
		for(int qh=0;qh<q.size();qh++){
			auto [r,c] = q[qh];
			cnt++;

			{//go right
				if(c + 1 < nax && right[r][c] == 0){
					if(!vis[r][c+1]){
						q.push_back({r , c+1});
						vis[r][c+1] = 1;
					}
				}
			}

			{//go left
				if(c > 0 && right[r][c-1] == 0){
					if(!vis[r][c-1]){
						q.push_back({r , c-1});
						vis[r][c-1] = 1;
					}
				}
			}

			{//go up
				if(r + 1 < nax && up[r+1][c] == 0){
					if(!vis[r+1][c]){
						q.push_back({r+1 , c});
						vis[r+1][c] = 1;
					}
				}
			}

			{//go down
				if(r > 0 && up[r][c] == 0){
					if(!vis[r-1][c]){
						q.push_back({r-1 , c});
						vis[r-1][c] = 1;
					}
				}
			}

		}
	}

	DSU d;
	int ans = 0;
	d.init(nax * nax , 0);
	for(int i=0;i<nax;i++){
		for(int j=0;j<nax;j++){
			if(!vis[i][j]){
				
				int r = i;
				int c = j;
				int cur = r * nax + c;
				{//go right
					if(c + 1 < nax && right[r][c] == 0){
						if(!vis[r][c+1])d.merge( cur , r * nax + c + 1 );
					}
				}

				{//go left
					if(c > 0 && right[r][c-1] == 0){
						if(!vis[r][c-1])d.merge( cur , r * nax + c - 1 );
					}
				}

				{//go up
					if(r + 1 < nax && up[r+1][c] == 0){
						if(!vis[r+1][c])d.merge( cur , (r + 1) * nax + c );
					}
				}

				{//go down
					if(r > 0 && up[r][c] == 0){
						if(!vis[r-1][c])d.merge( cur , (r - 1) * nax + c );
					}
				}


				ans = max(ans , d.sz[d.find(cur)]);
			}
		}
	}

	cout << ans << '\n';

}
