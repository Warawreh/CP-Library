#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> in(n);
	vector<bool> good(n,true);
	map<vector<int,int>,bool> E;
	vector<vector<int>> g(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
		if(u > v)swap(u,v);
		E[{u,v}] = true;
		in[u]++;
		in[v]++;
	}
	if(k*1LL*(k - 1)/2 > m){
		cout << -1 << '\n';
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(in[i] < k){
			q.push(i);
		}
	}
	while(q.size()){
		int u = q.front();
		good[u] = false;
		q.pop();
		for(int v : g[u]){
			if(good[v] == false)continue;
			if(in[v] == k){
				q.push(v);
			}
			in[v]--;
		}
		if(in[u] == k-1){
			bool good = true;
			for(int x : g[u]){
				if(in[x] < k)continue;
				for(int y : g[u]){
					if(in[y] < k)continue;
					if(x >= y)continue;
					if(E[{x,y}] == false)
						good = false;
				}
			}
			if(good){
				cout << 2 << '\n';
				for(int x : g[u]){
					if(in[x] < k)continue;
					cout << x << ' ';
				}
				cout << '\n';
				return;
			}
		}
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(good[i])ans.push_back(i);
	}
	if(ans.size()){
		cout << 1 << ' ' << ans.size() << '\n';
		for(int i : ans)
			cout << i+1 << ' ';
		cout << '\n';
	}else{
		cout << -1 << '\n';
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}



// for(int i=0;i<a.size();i++){
// 	cerr << a[i] << ' ';
// 	need[a[a.size()-i-1]] = true;
// }
// cerr << '\n';
// int cnt=0;
// for(int u : a){
// 	int b = 0;
// 	for(int v : g[u]){
// 		b+=need[v];
// 	}
// 	cnt+= b==k-1;
// }
// cerr << cnt << '\n';
// if(cnt == k){
// 	cout << 2 << '\n';
// 	for(int i=0;i<k;i++){
// 		cout << a[a.size()-i-1] + 1 << ' ';
// 	}
// 	cout << '\n';
// }else{
// 	cout << -1 << '\n';
// }
// return;