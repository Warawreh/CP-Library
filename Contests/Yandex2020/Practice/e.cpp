#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
pair<int,int> p;
int n;

bool check(int dist){
	vector<int> d(n + 1,-1);
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(g[i].size() == 1){
			d[i] = 0;
			q.push(i);
		}
	}
	p = {-1,-1};
	while(q.size()){
		int u = q.front();
		q.pop();
		if(dist == d[u]){
			if(p.first == -1)p.first = u;
			else p.second = u;
			continue;
		}
		for(int v : g[u]){
			if(d[v] != -1)continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	if(p.second == -1){
		if(p.first == -1)p.first = 1;
		p.second = 1;
		if(p.second == p.first)p.second = 2;
		return true;
	}
	while(q.size())q.pop();
	q.push(p.first);
	q.push(p.second);
	d = vector<int>(n+1 , -1);
	d[p.first] = d[p.second] = 0;
	while(q.size()){
		int u = q.front();
		if(dist < d[u]){
			return false;
		}
		q.pop();
		for(int v : g[u]){
			if(d[v] != -1)continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	return true;
}

int main(){
	fast
	cin>>n;
	g.resize(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int lo=0,hi=n,ans=n;
	while(lo <= hi){
		int md = (lo + hi)/2;
		if(check(md)){
			hi = md-1;
			ans = md;
		}else{
			lo = md+1;
		}
	}
	check(ans);
	cerr << ans << '\n';
	cout << p.first << ' ' << p.second << '\n';
}