#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
			x += x&(-x);
		}
	}
	ll get(int x){
		ll res = 0;
		while(x){
			res += tree[x];
			x -= x&(-x);
		}
		return res;
	}
	ll get(int l,int r){
		if(l > r)return 0;
		return get(r) - get(l-1);
	}
};

BIT tree;

int main(){
	fast
	int n;
	cin>>n;
	tree.init(n);
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second = i + 1;
	}
	sort(all(a));
	reverse(all(a));
	vector<ll> ans(n+1);
	for(int i=0;i<n;i++){
		ans[a[i].second] = tree.get(a[i].second);
		tree.update(a[i].second,a[i].first);
	}
	for(int i=1;i<=n;i++){
		ans[i] += ans[i-1];
		cout << ans[i] << ' ';
	}
}