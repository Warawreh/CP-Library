#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
vector<int> a,hv;
bool good = true;

int dfs(int u,int p){
	int mx = 0;
	for(int v : g[u]){
		if(v == p)continue;
		mx = max(mx , dfs(v,u));
	}
	int need = mx - a[u];
	// cerr << u << ' ' << a[u] << ' ' << mx << ' ' << need << '\n';
	if(need > 0){
		int at = lower_bound(all(hv) , need) - hv.begin();
		if(at < hv.size()){
			a[u] += hv[at];
		}else good = false;
	}
	mx = max(mx , a[u]);
	return mx;
}

int main(){
    fast
    int n,q;
    cin>>n>>q;

    g.resize(n);
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++){
    	int u,v;
    	cin>>u>>v;
    	u--;v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    {
	    vector<int> b(q);
	    for(int i=0;i<q;i++){
	    	cin>>b[i];
	    }
	    vector<bool> can(q * 1000 + 100);
	    can[0] = 1;
	    for(int i=0;i<q;i++){
	    	for(int j=can.size()-1;j>=0;j--){
	    		if(!can[j])continue;
	    		if(j + b[i] < can.size())
	    			can[j + b[i]] = can[j];
	    	}
	    }
	    for(int i=0;i<can.size();i++){
	    	if(can[i]){
	    		// cerr << i << '\n';
	    		hv.push_back(i);
	    	}
	    }
    }

	dfs(0,-1);
	if(good == false){
		cout << "-1\n";
	}else{
		ll sum = 0;
		for(int i=0;i<n;i++)
			sum += a[i];
		cout << sum << '\n';
	}

}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/