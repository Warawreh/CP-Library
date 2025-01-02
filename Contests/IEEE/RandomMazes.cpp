#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU{

   vector<int> dsu,sz,rnk,bad;

   void init(int n,int x){
      dsu = bad = sz = rnk = vector<int> (n+x);
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
      bad[u] |= bad[v];
      // rnk[v] = rnk[u] + 1;
      dsu[v] = u;
      return true;
   }   
};

string dir = "EWNS";
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int main(){
    fast
    int n,w;
    cin>>n>>w;
    DSU d;
    d.init(n * n + 1 , 0);
    d.bad[n-1] = 1;
    d.bad[n * (n - 1) + (n-1)] = 2;
    for(int i=0;i<w;i++){
    	int r,c;
    	char direc;
    	cin>>r>>c>>direc;
    	int nr,nc;
    	for(int x=0;x<4;x++){
    		if(dir[x] == direc){
    			nr = r + dx[x];
    			nc = c + dy[x];
    			break;
    		}
    	}
    	// if(i == 8)cerr << r << ' ' << c << ' ' << direc << '\n';
    	int v = d.find(n * nr + nc);
    	int u = d.find(n * r + c);

    	if((v == d.find(0) && u == d.find(n-1)) || (v == d.find(n-1) && u == d.find(0))){
    		cout << "M\n";
    		continue;
    	}

    	if(u == v){

    		if(d.find(0) == u){
    			cout << "L\n";
    			continue;
    		}else{
    			d.bad[u] |= 1;
    			if((d.bad[d.find(0)] & 2)){
		    		cout << "T\n";
		    	}else cout << "K\n";
    			continue;
    		}
    	}

    	if(u == d.find(0) || v == d.find(0)){
    		if(v == d.find(0))swap(u , v);

    		if((d.bad[v] & 1)){
    			cout << "L\n";
    			continue;
    		}
    	}


    	d.merge(u,v);

    	assert((d.bad[d.find(0)] & 1) == 0);
    	if((d.bad[d.find(0)] & 2)){
    		cout << "T\n";
    	}else cout << "K\n";

    }

}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/