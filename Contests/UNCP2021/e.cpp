#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
deque<int> st;

void dfs(int u,int p,int t=0){
	if(t)st.push_back(u);
	else st.push_front(u);
	for(int v : g[u]){
		if(v == p)continue;
		dfs(v , u , t);
		t = !t;
	}
}

int main(){
    fast
    int n;
    cin>>n;

    if(n == 1){
    	cout << 0 << '\n';
    	return 0;
    }
    
    g.resize(n);

    for(int i=0;i<n-1;i++){
    	int u,v;
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
    	if(g[i].size() == 1){
    		// st.push_back(i);
    		dfs(0,-1);
    		break;
    	}
    }
    for(int i : st)
    	cout << i << ' ';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/