#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

struct BIT{
	vector<ll> tree;
	int n;
	void init(int N){
		n = N;
		tree = vector<ll> (n+1,0);
	}
	void update(int x,ll val){
		while(x <= n){
			tree[x]+=val;
			tree[x]%=mod;
			x += x&(-x);
		}
	}
	ll get(int x){
		ll res = 0;
		while(x){
			res += tree[x];
			res %= mod;
			x -= x&(-x);
		}
		return res;
	}
	ll get(int l,int r){
		if(l > r)return 0;
		return get(r) - get(l-1);
	}
};

int main(){
	fast
	#ifndef LOCAL
		freopen("cups.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		BIT tree;
		tree.init(n + 1);
		vector<pair<ll,ll>> sum(n+1);
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum[a[i]].second = (sum[a[i]].second + n-i)%mod;
		}
		ll ans = 0;
		for(int i=0;i<n;i++){
			ll v = tree.get(a[i]+1 , n);
			ans = (ans + v)%mod;
			// cerr << v << '\n';

			sum[a[i]].second = (sum[a[i]].second - (n-i) + mod)%mod;
			sum[a[i]].first = (sum[a[i]].first + i+1)%mod;

			// cerr << tree.get(a[i],a[i]) << '\n';
			ll g = tree.get(a[i],a[i]);
			// cerr << a[i] << ' ' << (sum[a[i]].first * sum[a[i]].second)%mod << ' ' << (mod-g)%mod << '\n';

			tree.update(a[i],(mod-g)%mod);
			tree.update(a[i],(sum[a[i]].first * sum[a[i]].second)%mod);
		}
		cout << ans << '\n';
	}
}