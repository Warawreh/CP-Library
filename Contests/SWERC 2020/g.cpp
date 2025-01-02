#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int need;
vector<bool> vis;
vector<int> bf,cur;
ll best ;
vector<vector<int>> g;

void dfs(int u,int d,ll sum = 0){
	if(vis[u] && u != 1)return;
	// cerr << u << ' ' << d << '\n';
	if(d == need){
		if(bf.empty() || sum < best){
			best = sum;
			bf = cur;
		}
	}

	vis[u] = 1;
	for(int v : g[u]){
		cur.push_back(v);
		sum += v;
		dfs(v , d+1,sum);
		sum -= v;
		cur.pop_back();
	}
	vis[u] = 0;
}

int main(){
    fast
    int n,m;
    cin>>n>>m;
    if(n == 1){
    	if(m == 1)cout << 0 << '\n';
    	else cout << -1 << '\n';
    	return 0;
    }

    if(m >= n){
    	cout << -1 << '\n';
    	return 0;
    }

    need = m;
    vector<int> d(n);
    g.resize(n);
    vector<int> in(n);
    for(int i=1;i<n;i++){
    	for(int j=i;j<n;j+=i){
    		d[j]++;
    	}
    	int to = (i + d[i])%n;
    	g[to].push_back(i);
    	in[to]++;
    }
    vector<int> ans;
    vis.resize(n , 0);
    int cur = 1;
    while(need != 0){
    	if(vis[cur])break;
    	need--;
    	vis[cur] = 1;
    	ans.push_back(cur);
    	cur = (cur + d[cur])%n;
    }


    if(need == 0){
    	for(int a : ans){
    		cout << a << ' ';
    	}
    	cout << '\n';
    	return 0;
    }
    dfs(1,0);

    if(bf.size() + ans.size() != m){
    	cout << -1 << '\n';
    	return 0;	
    }
    // if(bf.size() + ans.size() != m){
    // 	cout << -1 << '\n';
    // 	return 0;
    // }
    reverse(all(bf));
    for(int a : bf){
		cout << a << ' ';
	}
	for(int a : ans){
		cout << a << ' ';
	}
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/

