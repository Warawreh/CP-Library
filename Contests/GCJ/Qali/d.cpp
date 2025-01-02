#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int t,n,q;
vector<vector<int>> g;

vector<int> topSort(){
	vector<int> in(n);
	for(int u=0;u<n;u++){
		for(int v : g[u])
			in[v]++;
	}
	vector<int> res;
	queue<int> q;
	for(int i=0;i<n;i++){
		if(!in[i])q.push(i);
	}
	assert(q.size() == 1);
	while(q.size()){
		int u = q.front();
		q.pop();
		res.push(u);
		for(int v : g[u]){
			in[v]--;
			if(in[v] == 0){
				q.push(v);
			}
		}
	}
	return res;
}

map<vector<int>,int> mp;

int ask(vector<int> x){
	vector<int> tmp = x;
	sort(all(tmp));
	if(mp[tmp])return mp[tmp] - 1;

	cout << x[0] + 1 << ' ' << x[1] + 1 << ' ' << x[2] + 1 << '\n';
	fflush(stdout);
	int res;
	cin>>res;
	res--;
	for(int i=0;i<3;i++)
		if(res == x[i]){
			mp[tmp] = i + 1;
			return mp[tmp] - 1;
		}
	assert(0);
}

int solve(){
	g.clear();
	g.resize(n);
	int a=0,b=1;
	for(int c=2;c<n;c++){
		int res = ask({a,b,c});
		if(res == 0)a = c;
		else if(res == 1)b = c;
	}
	int lst = -1;
	vector<pair<int,int>> gr;
	
	
	for(int i=0;i<n;i++){
		if(i == a)continue;
		if(lst == -1)lst = i;
		else{
			int res = ask(a,i,lst);
			assert(res != 0);
			if(res == 1){
				g[res].push_back(i);
				g[i].push_back(lst);
			}else{
				g[res].push_back(lst);
				g[lst].push_back(i);
			}
			gr.push_back({i,lst});
			lst = -1;
		}
	}
	
}

int main(){
	fast
	cin>>t>>n>>q;
	for(int T=1;T<=t;T++){
		solve();
	}
}