#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int nax = 2e5 + 100;

vector<pair<int,char>> g[nax];
vector<int> cost,fr,cost2;
int n,m;
string s;

void bfs(int st){
	queue<int> q;
	cost = vector<int> (n+1,-1);
	cost[st] = 0;
	q.push(st);
	while(q.size()){
		int u = q.front();
		q.pop();
		for(pair<int,char> node : g[u]){
			int v = node.first;
			if(cost[v] != -1)continue;
			cost[v] = cost[u]+1;
			q.push(v);
		}
	}
}

void bfs2(int st){
	fr = vector<int> (n+1,-1);
	cost2 = vector<int> (n+1,30);
	vector<int> q;
	q.push_back(st);
	cost2[st] = 0;
	while(q.size()){
		int mn=30;
		vector<int> nxt;
		for(int u : q){
			for(pair<int,char> node : g[u]){
				int v = node.first;
				int w = node.second - 'a';
				// cout << u << ' ' << v << ' ' << w << '\n';
				if(cost[v] != cost[u] - 1)continue;
				if(w >= cost2[v])continue;
				cost2[v] = w;
				fr[v] = u;
				if(w < mn){
					mn = w;
					nxt.clear();
				}
				if(w <= mn)
					nxt.push_back(v);
			}
		}

		q = nxt;
		if(cost[q[0]] == 0)break;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		char c;
		cin>>u>>v>>c;
		g[u].push_back({v,c});
		g[v].push_back({u,c});
	}
	bfs(n);
	s = string(cost[1],char('a' + 26));
	bfs2(1);
	int at = n;
	vector<int> ans;
	string s;
	while(at != -1){
		ans.push_back(at);
		if(at!=1)s += char(cost2[at] + 'a');
		at = fr[at];
	}
	reverse(all(ans));
	reverse(all(s));
	cout << s.size() << '\n';
	for(int i : ans)
		cout << i << ' ';
	cout << '\n' << s << '\n';
}	