#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,c;
vector<vector<pair<int,int>>> g;
map<int,int> dp[52][22];
map<int,bool> vis[52][22];

int main(){
    fast
    cin>>n>>m>>c;
    g.resize(n);
    for(int i=0;i<m;i++){
    	int u,v,col;
    	cin>>u>>v>>col;
    	g[u].push_back({v,col});
    	g[v].push_back({u,col});
    }
    vector<int> notAllowed(n);
    for(int u=0;u<n;u++){
    	for(auto &[v,col] : g[u]){
    		notAllowed[u] |= (1 << col);
    	}
    }

    priorty_queue<vector<int>> q;
    dp[0][c][0] = 0;
    vis[0][c][0] = 1;
    q.push({0,0,c,0});

    while(q.size()){
    	vector<int> &cur = q.top();
    	int d = -cur[0];
    	int u = cur[1];
    	int lc = cur[2];
    	int nac = cur[3];

    	if(u == n-1){
    		cout << d << '\n';
    		return 0;
    	}

    	if(d > dp[u][lc][nax])continue;

    	for(auto &[v,col] : g[u]){
    		if(lc == c){
    			{//top deck
    			
	    			if((nac >> col) & 1){

	    			}else{
	    				int nd = d + 1;
	    				int nnac = 0;
	    				if(vis[v][c][nnac] == 0){
	    					dp[v][c][nnac] = 1e9;
	    					vis[v][c][nnac] = 1;
	    				}

	    				if(nd < dp[v][c][nnac]){
	    					dp[v][c][nnac] = nd;
	    					q.push({-nd , v , c , nnac});
	    				}
	    			}

    			}

    			{//use door
    				int nd = d;
    				int nnac = (nac | notAllowed[u]);
    				if(vis[v][col][nnac] == 0){
    					dp[v][col][nnac] = 1e9;
    					vis[v][col][nnac] = 1;
    				}

    				if(nd < dp[v][col][nnac]){
    					dp[v][col][nnac] = nd;
    					q.push({-nd , v , col , nacc});
    				}
    			}
    		}else{//must use car
    			if(lc == col){
    				int nd = d;
    				int nnac = nac;
    				if(vis[v][c][nnac] == 0){
    					dp[v][c][nnac] = 1e9;
    					vis[v][c][nnac] = 1;
    				}

    				if(nd < dp[v][c][nnac]){
    					dp[v][c][nnac] = nd;
    					q.push({-nd , v , c , nnac})
    				}
    			}
    		}

    	}

    }

}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/