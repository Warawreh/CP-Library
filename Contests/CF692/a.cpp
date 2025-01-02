#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> dsu,sz;

void init(int n,int x){
	dsu = sz = vector<int> (n+x);
	iota(dsu.begin()+x,dsu.end(),x);
	fill(sz.begin(),sz.end(),1);
}

int find(int u){
	return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
}

void merge(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[u] < sz[v])swap(u,v); // enable for fast dsu
	sz[u] += sz[v];
	dsu[v] = u;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		init(n,0);
		int ans = 0;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			if(a == b)continue;
			// r.push_back({a,b});
			ans++;
			if(find(a) == find(b))ans++;
			else{
				merge(a,b);
			}
		}

		// int ex = 0;
		// for(int i=0;i<r.size();i++){
		// 	int a = r[i][0];
		// 	int b = r[i][1];
		// 	if(x[b] && y[a])ex++;
		// }
		// ex/=2;

		cout << ans << '\n';
	}
}