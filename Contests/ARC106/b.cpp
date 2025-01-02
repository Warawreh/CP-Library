#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> dsu,sz,rnk,val;
vector<ll> a;

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
	a[u] += a[v];
	a[v] = 0;
	sz[u] += sz[v];
	rnk[v] = rnk[u] + 1;
	dsu[v] = u;
}

int main(){
	fast
	int n,m;
	cin>>n>>m;
	init(n,0);
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a[i]-=x;
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		merge(u,v);
	}
	bool good = true;
	for(int i=0;i<n;i++)good &= (a[find(i)]== 0);
	cout << (good ? "Yes\n" : "No\n");
}