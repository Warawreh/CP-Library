/*
Name: Fenwick Tree 2D (2D BIT)
Description: Ranged query for 2D ranges and single cell update
Time: O(NM) initlize / O(LogN*LogM) update and get
Space: O(NM)
*/

template<int SZ> struct BIT_2D{
	vector<vector<ll>> tree;
	int n,m;
	void init(int n,int m){
		this->n = n;
		this->m = m;
		tree = vector<vector<ll>> (n+1 , vector<ll> (m+1,0));
	}
	void update(int r,int c,ll val){
		for (int i = r; i <= n; i += (i & -i))
			for (int j = c; j <= m; j += (j & -j))
				tree[i][j] += val;
	}
	ll get(int r,int c){
		ll res = 0;
		for (int i = r; i > 0; i -= (i & -i))
			for (int j = c; j > 0; j -= (j & -j)){
				res += tree[i][j];
			}
		return res;
	}
	ll get(int r1,int c1,int r2,int c2){
		return get(r2,c2) - get(r1-1,c2) - get(r2,c1-1) + get(r1-1,c1-1);
	}
};
