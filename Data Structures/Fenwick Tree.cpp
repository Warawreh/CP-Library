/*
Name: Fenwick Tree (BIT)
Description: Range query data structure for single update and range query for reversable functions
Time: O(N) initilize / O(logN) update & get
Space: O(N)
Resources: https://cp-algorithms.com/data_structures/fenwick.html
*/

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
		return get(r) - get(l-1);
	}
};
