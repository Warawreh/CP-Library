#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5;
int sz[nax],to[nax],fr[nax],in[nax];
vector<vector<int>> c;

int main(){
    fast
    int m,n,q;
    cin>>m>>n>>q;
    sz[0] = m;
    fr[0] = -1;
    c.resize(n);

    memset(to,-1,sizeof(to));

    for(int i=0;i<n;i++){
    	char t;
    	int x,y,z;
    	cin>>t>>x>>y>>z;
    	x--;y--;z--;
    	if(t == 'S'){
	    	c[i] = {0,x,y,z};
    		to[x] = fr[y] = fr[z] = i;
    		in[i] = 1;
    	}else{
    		c[i] = {1,x,y,z};
    		to[x] = to[y] = fr[z] = i;
    		in[i] = 2;
    	}
    }

    {
	    vector<int> q = {0};
	    for(int qh=0;qh<q.size();qh++){
	    	int u = q[qh];

    		int id = to[u];
    		if(id == -1)continue;
	    	in[id]--;
	    	if(in[id] == 0){
	    		if(c[id][0] == 0){
	    			int p = c[id][1];
	    			int l = c[id][2];
	    			int r = c[id][3];
	    			sz[l] = (sz[p] + 1)/2;
	    			sz[r] = sz[p] / 2;

	    			q.push_back(l);
	    			q.push_back(r);
	    		}else{
	    			sz[c[id][3]] = sz[c[id][2]] + sz[c[id][1]];
	    			q.push_back(c[id][3]);
	    		}
	    	}
	    }

    }
    // for(int i=0;i<4;i++){
    // 	cout << sz[i] << '\n';
    // }

    while(q--){
    	int u,k;
    	cin>>u>>k;
    	u--;
    	k--;
    	if(k >= sz[u]){
    		cout << "none\n";
    		continue;
    	}

    	while(u){
    		int ou = u;
    		int i = fr[u];

    		// cerr << u << ' ' << k << '\n';

    		if(c[i][0] == 0){//Comes from Split

    			k = k*2 + (u == c[i][3]);
    			u = c[i][1];

    		}else{//Comes from merge

    			int p1 = c[i][1];
    			int p2 = c[i][2];
    			int x = min(sz[p1] , sz[p2]);

    			if(k < x*2){
    				if(k % 2 == 0){
    					u = p1;
    				}else{
    					u = p2;
    				}
					k/=2;
    			}else{
					k -= x;
    				if(sz[p1] > sz[p2]){
    					u = p1;
    				}else u = p2;
    			}

    		}
    		if(ou == u){
    			assert(0);
    		}
    	}

    	cout << k + 1 << '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/