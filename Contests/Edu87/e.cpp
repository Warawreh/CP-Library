#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
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
	int n,q;
	cin>>n>>q;
	tree.init(n+1);
	for(int i=0;i<n;i++){
		int b;
		b = 1;
		tree.update(b,1);
	}
	int e = -1;
	for(int i=0;i<q;i++){
		e = 1 * (i % 2 ? -1 : 1);
		if(e < 0){
			e = -e;
			int md,lo=1,hi=n,at=-1;
			while(lo <= hi){
				md = (lo + hi )/2;
				int h = tree.get(md);
				if(h >= e){
					hi = md-1;
					at = md;
				}else lo = md+1;
			}
			tree.update(at,-1);
		}else{
			tree.update(e,1);
		}
	}
	for(int i=1;i<=n;i++){
		if(tree.get(i)){
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
}