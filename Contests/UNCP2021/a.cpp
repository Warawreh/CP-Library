#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
    fast
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	u--;v--;
    	g[u].push_back({v,w});
    }
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    vector<pair<int,int>> ch;
    for(int i=0;i<n;i++){
    	dist[i][i] = 0;
    	ch.push_back({i,i});
    }

    vector<vector<int>> e(q);
    for(int i=0;i<q;i++){
    	int u,v,x;
    	cin>>u>>v>>x;
    	u--;v--;
    	e[i] = {u,v,x,(int)1e9};
    	if(u == v)e[i][3] = x;
    }

    for(int U=1;U<=n;U++){
    	vector<pair<int,int>> nxt;
    	vector<vector<int>> ndist = dist;
    	for(auto &[u,v] : ch){
    		for(auto &[k,w] : g[v]){
    			int nd = dist[u][v] + w;
    			if(nd < dist[u][k]){
    				ndist[u][k] = min(ndist[u][k] , nd);
    				nxt.push_back({u,k});
    			}
    		}
    	}

    	sort(all(nxt));	
		nxt.resize(unique(all(nxt)) - nxt.begin());
		dist = ndist;
		ch = nxt;

		for(int i=0;i<q;i++){
			e[i][3] = min(e[i][3] , dist[e[i][0]][e[i][1]] + e[i][2] * (U + 1));
			// cerr << U << ' ' << i << ' ' << e[i][2] << ' ' << e[i][3] << '\n';
		}

    }
    for(int i=0;i<q;i++){
    	if(e[i][3] >= 1e9)e[i][3] = -1;
    	cout << e[i][3] << '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/