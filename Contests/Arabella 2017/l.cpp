#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	ll h,sum;

	node(){
		h = sum = 0;
	}
};

struct SegTree{
    typedef node T;
    int n;
    vector<T> seg;
    vector<ll> lazy;
    const T oo = node();

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n);
        lazy = vector<ll>(4*n);
    }

    T merge(T l, T r){
    	T res = node();
    	res.sum = l.sum + r.sum;
    	res.h = max(l.h , r.h);
        return res;
    }

    void pro(int n,int s,int e){
    	if(lazy[n] == 0)return;
        seg[n].h = lazy[n];
        seg[n].sum = lazy[n] * 1LL * (e - s + 1);
        if(s != e){
            lazy[n+n] = lazy[n];
            lazy[n+n+1] = lazy[n];
        }
        lazy[n] = 0;

    }

    void update(int l,int r,ll val,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] = val;
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

    void update(int l,int r,ll val){
        update(l,r,val,1,1,n);
    }

    void update(int at,ll val){
        update(at,at,val,1,1,n);
    }

    ll get(int l,int r){
        return get(l,r,1,1,n).h;
    }

};

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n + 1),pre(n+1),suf(n+1);
	ll sum = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum += a[i];
		pre[i] = max(pre[i-1] , a[i]);
	}

	SegTree tree(n);
	for(int i=n;i>=1;i--){
		suf[i] = max((i + 1 <= n ? suf[i+1] : 0) , a[i]);
		int h = min(pre[i] , suf[i]);
		// cerr << i << ' ' << h << '\n';
		tree.update(i , h);
	}

	ll mx = pre[n];
	ll l=0,r=0;
	for(int i=1;i<=n;i++){
		if(tree.get(i,i) == mx){
			if(l == 0)l = i;
			r = i;
		}
	}

	while(q--){
		char o;
		cin>>o;
		if(o == 'P')cout << tree.seg[1].sum - sum << '\n';
		else{
			ll x,v;
			cin>>x>>v;
			sum += v;

			a[x] += v;
			if(a[x] > mx){
				tree.update(x , a[x]);
				if(x >= l && x <= r){
				}else{
					if(x < l){
						tree.update(x + 1,l , mx);
					}else{
						assert(x > r);
						tree.update(r,x - 1,mx);
					}
				}
				l = r = x;
				mx = a[x];
			}else{



				ll curVal = tree.get(x,x);
				if(curVal >= a[x])continue;

				if(x >= l && x <= r){

				}else{
					if(x < l){

						int lo = x,hi = l,to = l;
						while(lo <= hi){
							int md = (lo + hi)/2;
							if(tree.get(md,md) > a[x]){
								hi = md-1;
								to = md;
							}else lo = md+1;
						}
						tree.update(x , to-1 , a[x]);


					}else{

						int lo = r,hi = x,fr = r;

						while(lo <= hi){
							int md = (lo + hi)/2;
							if(tree.get(md,md) > a[x]){
								lo = md+1;
								fr = md;
							}else hi = md-1;
						}

						tree.update(fr+1 , x , a[x]);

					}

				}

				if(a[x] == mx){
					l = min(l , x);
					r = max(r , x);
				}
			}

		}
	}

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