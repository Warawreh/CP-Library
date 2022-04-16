/*
Name: Ranged Fenwick Tree (Ranged BIT)
Description: Range query data structure for range update and range query for reversable functions
Time: O(N) initilize / O(logN) update & get
Space: O(N)
Resources: https://cp-algorithms.com/data_structures/fenwick.html
*/

struct BIT{
	vector<ll> B1,B2;
	int n;
	void init(int N){
		n = N;
		B1 = B2 = vector<ll> (n+1,0);
	}
	void update(vector<ll> &tree,int x,ll val){
		while(x <= n){
			tree[x]+=val;
			x += x&(-x);
		}
	}
	ll get(vector<ll> &tree,int x){
		ll res = 0;
		while(x){
			res += tree[x];
			x -= x&(-x);
		}
		return res;
	}
    void ranged_update(int l,int r,int x){
    	update(B1,l,x);
    	update(B1,r+1,-x);
    	update(B2,l,x*(l-1));
    	update(B2,r+1,-x*r);
    }

    ll get(ll id){
    	return get(B1, id) * id - get(B2,id);
    }

	ll get(int l,int r){
		return get(r) - get(l-1);
	}
};
