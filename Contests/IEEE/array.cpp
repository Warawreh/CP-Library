#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct BIT{
	vector<ll> tree;
	int n;
	void init(int N){
		n = N;
		tree = vector<ll> (n+1,0);
	}
	void update(int x,ll val){
		while(x <= n){
			tree[x]+=val;
			x += x&(-x);
		}
	}
	ll get(int x){
		ll res = 0;
		while(x){
			res += tree[x];
			x -= x&(-x);
		}
		return res;
	}
	ll get(int l,int r){
		return get(r) - get(l-1);
	}
};


int main(){
    fast
    int n,m,p;
    cin>>n>>m>>p;
    vector<int> pre(n+1,-1);
    pre[0] = 0;
    vector<vector<pair<int,int>>> g(n+1);

    for(int i=0;i<m;i++){
    	int l,r,k;
    	cin>>l>>r>>k;
    	g[l-1].push_back({r , k});
    	g[r].push_back({l-1 , k});
    }

    vector<bool> vis(n + 1 , false);

    function<void(int)> dfs = [&](int u){
    	if(vis[u])return;
    	vis[u] = 1;
    	assert(pre[u] != -1);

    	for(auto &[v,k] : g[u]){
    		int val = 0;
    		if(v > u){
    			val = (k + pre[u]) % p;
    		}else if(v < u){
    			val = (pre[u] - k + p)%p;
    		}else assert(0);

    		if(vis[v]){//check
    			assert(pre[v] != -1);
    			if(val != pre[v]){
    				cout << "None\n";
    				exit(0);
    			}
    		}else{
    			pre[v] = val;
    			dfs(v);
    		}
    	}


    	return;
    };

    for(int i=0;i<=n;i++){
    	if(vis[i])continue;
    	if(pre[i] == -1)pre[i] = pre[i-1];
    	dfs(i);
    }
    for(int i=1;i<=n;i++){
    	cout << (pre[i] - pre[i-1] + p)%p << ' ';
    }


}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/

/*
1 2 3 4  5 6 7  8 9 0 1 2 3 4 5 6 7 8 9  0
0 0 0 18 0 2 14 0 4 0 0 0 0 0 0 0 0 0 18 0
  ^          ^
         ^                            ^
    ^      ^
           ^      ^
             ^                        ^      
0 0 0 0  0 1 15 0 1 0 0 0 0 0 0 0 0 0 17 0


20 5 19
2 7 15
5 19 0
3 6 1
6 9 1
7 19 17


1 2 3 4  5  6 7  8 9 0 1 2 3 4 5 6 7 8 9  0
0 0 0 18 18 

*/