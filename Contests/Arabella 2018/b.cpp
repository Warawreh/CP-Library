#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> ans,sz,leafs,type;
vector<vector<int>> g;

const int nax = 3e5 + 100;

int c[2][nax];
int cnt[nax];
bool big[nax];
multiset<int> st;

void add(int v, int p, int x,int b){

	if(type[v] == -1)type[v] = b;
	{
		ll val = c[type[v]][v] - 1e5;
		ll cur = cnt[ c[type[v]][v] ];
		if(val != 0){
			cur += cnt[ -val + (int)1e5 ];
		}
		st.erase(st.find(cur));
	}

    cnt[ c[type[v]][v] ] += x;

    {
    	ll val = c[type[v]][v] - 1e5;
		ll cur = cnt[ c[type[v]][v] ];
		if(val != 0){
			cur += cnt[ -val + (int)1e5 ];
		}
	    st.insert(cur);
    }
    
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x, b);
}

void dfs(int v, int p, bool keep,int b){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0, !b); 
    if(bigChild != -1)
        dfs(bigChild, v, 1 , b), big[bigChild] = 1; 
    add(v, p, 1 , b);

    int curLeafs = leafs[v];
    if(g[v].size() == 2 && p != -1)curLeafs++;
    if(g[v].size() == 1 && p == -1)curLeafs++;

    if(curLeafs <= 2){
    	// if(v == 10)cerr << cnt[  ]
	    ans[v] = min(ans[v] , sz[v] - *st.rbegin());	
    }

    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1 , b);
}

void calc(int u,int p,int d){
	c[1][u] = - c[0][u] + d + 1e5;
	c[0][u] = c[0][u] + d + 1e5;
	sz[u] = 1;

	cerr << u + 1 << ' ' << c[1][u] - 1e5 << ' ' << c[0][u] - 1e5 << '\n';

	if(g[u].size() == 1 && p != -1)leafs[u] = 1;

	for(int v : g[u]){
		if(v == p)continue;
		calc(v,u,d+1);
		leafs[u] += leafs[v];
		sz[u] += sz[v];
	}
}

void solve(){
	int n;
	cin>>n;

	sz = leafs = vector<int>(n);
	type = vector<int>(n,-1);
	ans = vector<int>(n , 1e9);
	g.clear();
	g.resize(n);
	st.clear();

	for(int i=0;i<n;i++)cin>>c[0][i];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	calc(0,-1,0);

	for(int i=0;i<n;i++)st.insert(0);
	dfs(0,-1,0 , 0);
	type = vector<int>(n,-1);
	dfs(0,-1,0 , 1);

	for(int i=0;i<n;i++){
		if(ans[i] == 1e9)ans[i] = -1;
		cout << ans[i] << ' ';
	}
	cout << '\n';
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