#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
    typedef int T;
    int n;
    vector<T> seg,lazy;
    const T oo = 0;

    SegTree(){

    }

    SegTree(int _n){
        init(_n);
    }

    void init(int _n){
    	n = _n;
        seg = lazy = vector<T>(4*n);
    }

    T merge(T l, T r,int b1,int b2){
    	return max(l * !b1 , r * !b2);	
    }

    void update(int l,int r,T val,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
        	if(val == -1){
        		lazy[n]++;
        	}else if(val == -2){
        		lazy[n]--;
        	}else{
            	seg[n] = val;
            }
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1] , lazy[n+n] , lazy[n+n+1]);
    }

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

};

SegTree tree;
vector<int> c;
vector<vector<int>> g;
int ans,n;

vector<int> sz,fr,to,vals,hv,atC,id;
int T;
vector<bool> isCentroid;

void dfs(int u,int p){
   fr[u] = ++T;
   id[fr[u]] = u;
   sz[u] = 1;
   for(int v : g[u]){
      if(v == p || isCentroid[v])continue;
      dfs(v,u);
      sz[u] += sz[v];
   }
   to[u] = T;
}

void go1(int u,int p,int d){
	if(hv[c[u]])return;

	hv[c[u]] = 1;
	vals[fr[u]] = d;

	int at = atC[c[u]];
	if(at){
		tree.update(fr[at - 1] , to[at - 1] , -1);
	}

	ans = max(ans , d + tree.seg[1] );

	for(auto v : g[u]){
		if(v == p || isCentroid[v])continue;
		go1(v , u , d + 1);
	}

	hv[c[u]] = 0;
	if(at){
		tree.update(fr[at - 1] , to[at - 1] , -2);
	}

}

void decompose(int u){

	T=0;
   dfs(u,-1);
   int lst = -1,groupSize = sz[u];

   while(true){
      int nxt = -1;
      for(int v : g[u]){
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
   T = 0;
   dfs(u , -1);

   hv[c[u]] = 1;
   for(int v : g[u]){
      if(isCentroid[v])continue;
      go1(v,u,1);


      for(int x = fr[v];x <= to[v];x++){
      	atC[c[id[x]]] = id[x] + 1;
      	tree.update(x , vals[x]);
      }
   }
   hv[c[u]] = 0;


   for(int v = fr[u];v<=to[u];v++){
   	vals[v] = 0;
   	atC[c[id[v]]] = 0;
   	tree.update(v , 0);
   }

   for(int v : g[u]){
      if(isCentroid[v])continue;
      decompose(v);
   }
}

void solve(){
	
	cin>>n;

	{//init
		c = vals = id = atC = hv = fr = to = sz = vector<int>(n+1,0);
		isCentroid = vector<bool>(n,0);
		g.clear();
		g.resize(n);
		ans = 0;
		tree.init(n);
	}


	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	decompose(0);

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/