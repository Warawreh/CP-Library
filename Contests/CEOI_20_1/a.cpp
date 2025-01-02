#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

ll inv_mod;

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res)%mod;
	if(b%2)res = (res * a)%mod;
	return res;
}

ll cnt(ll n,ll m){
	ll res = (((m * n)%mod) * (((n+1)*(m+1))%mod))%mod;
	return (res * inv_mod)%mod;
}

vector<int> dsu,sz,rnk;
vector<ll> len;

void init(int n,int x){
	dsu = sz = rnk = vector<int> (n+x);
	len.resize(n);
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
	len[u] += len[v];
	len[u] %= mod;
	len[v] = 0;
	dsu[v] = u;
}

int main(){
	fast
	inv_mod = Pow(4,mod-2);
	int n;
	cin>>n;
	init(n,0);
	vector<vector<int>> f(n,vector<int>(3));
	vector<bool> found(n,false);
	for(int i=0;i<n;i++){
		cin>>f[i][0];
		f[i][1] = i;
	}
	for(int i=0;i<n;i++){
		cin>>f[i][2];
		len[i] = f[i][2];
	}
	sort(all(f));
	reverse(all(f));
	ll ans = 0;
	for(int id=0;id<n;id++){
		int i = f[id][1];
		found[i] = 1;
		if(i && found[i-1]){
			ans = (ans - cnt(f[id][0] , len[find(i-1)]) + mod)%mod;
			merge(i,i-1);
		}
		if(i+1 < n && found[i+1]){
			ans = (ans - cnt(f[id][0] , len[find(i+1)]) + mod)%mod;
			merge(i,i+1);
		}
		ans = (ans + cnt(f[id][0] , len[find(i)]))%mod;
	}
	cout << ans << '\n';
}