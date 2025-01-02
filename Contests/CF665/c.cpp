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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		init(n,0);
		vector<int> a(n);
		int mn = 2e9;
		int at = -1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i] < mn)at = i;
			mn = min(mn , a[i]);
		}
		for(int i=0;i<n;i++){
			if(a[i] % mn == 0){
				merge(i,at);
			}
		}
		vector<vector<int>> v(n);
		for(int i=0;i<n;i++)v[find(i)].push_back(a[i]);
		for(int i=0;i<n;i++){
			sort(all(v[i]));
			reverse(all(v[i]));
		}
		vector<int> b;
		for(int i=0;i<n;i++){
			b.push_back(v[find(i)].back());
			v[find(i)].pop_back();
		}
		cout << (is_sorted(all(b)) ? "YES\n" : "NO\n");
	}	
}