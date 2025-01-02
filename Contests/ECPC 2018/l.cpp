#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
    typedef int T;
    int n;
    vector<T> seg,lazy;
    const T oo = 0;

    SegTree(){

    }

    SegTree(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n);
    }

    void init(int _n){
    	n = _n;
        seg = lazy = vector<T>(4*n);	
    }

    T merge(T l, T r){
        return l + r;
    }

    void build(int n,int s,int e){
        if(s == e){
            seg[n] = 1;
            return;
        }
        build(n+n, s, (s+e)/2);
        build(n+n+1, (s+e)/2+1, e);
        seg[n] = merge(seg[n+n] , seg[n+n+1]);

    }

    void pro(int n,int s,int e){
    	lazy[n] %= 2;
    	if(lazy[n]){
	        seg[n] = -seg[n];
    	}
        if(s != e){
            lazy[n+n] += lazy[n];
            lazy[n+n+1] += lazy[n];
        }
        lazy[n] = 0;

    }

    void update(int l,int r,T val,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] += val;
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

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

    void build(){
        build(1,1,n);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};

SegTree tree;

const int nax = 1e5 + 10;

void solve(){
	int q;
	cin>>q;

	vector<int> x(q);
	for(int i=0;i<q;i++){
		cin>>x[i];

		if(x[i] == 0)cout << 0 << '\n';
		else cout << tree.get(1 , x[i]) << '\n';

		tree.update(x[i]+1,nax , 1);
	}

	for(int i=0;i<q;i++){
		tree.update(x[i] + 1 , nax , 1);
	}
}


int main(){
	fast
	freopen("reflection.in","r",stdin);	

	tree.init(nax);
	tree.build();

	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/