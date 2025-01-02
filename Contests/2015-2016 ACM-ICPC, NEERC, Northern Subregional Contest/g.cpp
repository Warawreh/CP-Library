#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

const int nax = 1e5 + 100;

vector<int> g[nax];
map<pair<int,int> , bool> e;

int main(){
	freopen("graph.in" , "r" , stdin);
	freopen("graph.out" , "w" , stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> in(n+1);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		if(e[{u,v}])continue;
		// cout << u << ' ' << v << '\n';
		e[{u,v}] = 1;
		g[u].push_back(v);
		in[v]++;
	}
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		if(!in[i]){
			q.push(-i);
		}
	}
	vector<pair<int,int>> edges;
	while(q.size()){
		int u = -q.top();
		q.pop();
		vector<int> tmp;
		while(k && q.size()){
			tmp.push_back(u);
			u = -q.top();
			q.pop();
			in[tmp.back()]++;
			g[u].push_back(tmp.back());
			edges.push_back({u , tmp.back()});
			k--;
		}
		cout << u << ' ';
		for(int v : g[u]){
			in[v]--;
			if(!in[v])q.push(-v);
		}
	}
	cout << '\n';
	cout << edges.size() << '\n';
	for(pair<int,int> i : edges){
		cout << i.first << ' ' << i.second << '\n';
	}
}