#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	ll sum,marked;

	node(){
		sum = marked = 0;
	}
};

struct SegTree{
    typedef node T;
    int n;
    vector<T> seg;
    vector<int> lazy;
    const T oo = node();

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n);
        lazy = vector<int>(4*n);
    }

    T merge(T l, T r){
    	T res = node();
    	res.sum = l.sum + r.sum;
    	res.marked = l.marked + r.marked;
        return res;
    }

    void build(int n,int s,int e,vector<int> &a){
        if(s == e){
            seg[n].sum = a[s-1];
            return;
        }
        build(n+n, s, (s+e)/2,a);
        build(n+n+1, (s+e)/2+1, e,a);
        seg[n] = merge(seg[n+n] , seg[n+n+1]);

    }

    void pro(int n,int s,int e){
    	if(lazy[n]){
    		seg[n].marked = 1;
    		seg[n].sum = e - s + 1;
    	}
        if(s != e){
            lazy[n+n] |= lazy[n];
            lazy[n+n+1] |= lazy[n];
        }
        lazy[n] = 0;

    }

    void update(int l,int r,int val,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] = 1;
            pro(n,s,e);
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1]);
    }

    T get(int l,int r,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return oo;
        if(s >= l && e <= r){
            return seg[n];
        }
        return merge(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
    }

    void update(int l,int r,int val){
        update(l,r,val,1,1,n);
    }

    void update(int at,int val){
        update(at,at,val,1,1,n);
    }

    void build(vector<int> &a){
        build(1,1,n,a);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i] %= 2;
	}

	SegTree tree(n);
	tree.build(a);

	vector<pair<int,int>> seg;
	int ans = 0;
	for(int i=0;i<m;i++){
		int l,r,p;
		cin>>l>>r>>p;
		if(p == 1){
			int tot = tree.get(l,r).sum;
			tot = (r - l + 1) - tot;
			ans += tot;
			tree.update(l,r,1);
		}else{
			seg.push_back({r,l});
		}
	}
	
	set<int> good;
	set<int> taken;

	for(int i=1;i<=n;i++){
		if(tree.get(i,i).marked == 0){
			if(a[i - 1] == 1)
				good.insert(i);
			else
				taken.insert(i);
		}
	}
	
	sort(all(seg));
	for(auto &[r,l] : seg){
		auto it = taken.lower_bound(l);
		if(it != taken.end() && *it <= r)continue;
		it = good.upper_bound(r);
		if(it == good.begin()){
			cout << -1 << '\n';
			return;
		}
		it--;
		if(*it < l){
			cout << -1 << '\n';
			return;	
		}
		ans++;
		taken.insert(*it);
		good.erase(it);
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();

	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/