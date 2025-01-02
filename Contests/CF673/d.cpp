#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> dsu,sz,rnk;

void init(int n,int x){
	dsu = sz = rnk = vector<int> (n+x);
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
	// if(rnk[u] > rnk[v])swap(u,v);
	sz[u] += sz[v];
	rnk[v] = rnk[u] + 1;
	dsu[v] = u;
}

int main(){
	fast
	int n,m,q;
	cin>>n>>m>>q;
	init(n,1);
	for(int i)
}