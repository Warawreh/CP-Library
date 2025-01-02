#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 2e9;
const int N = 2e5 + 10;
int n,q;
int a[N];

struct Node{
    ll sum;
    int mx, mn, mx2, mn2;
    int mxc, mnc;

} node[N << 2];

struct segtree
{
	#define lson(x) (x << 1)
	#define rson(x) (x << 1 | 1)
    int _sz;
    explicit segtree(int size) : _sz(size){
        
    }

    inline void pushdown(int x, int lx, int rx, int mid)
    {
        if (node[x].mn > node[lson(x)].mn) update_ckmax(lson(x), node[x].mn);
        if (node[x].mn > node[rson(x)].mn) update_ckmax(rson(x), node[x].mn);
    }

    inline void pushup(Node& cur, const Node& lson, const Node& rson)
    {
        cur.sum = lson.sum + rson.sum;

        if (lson.mn < rson.mn)
        {
            cur.mn = lson.mn, cur.mnc = lson.mnc;
            cur.mn2 = min(rson.mn, lson.mn2);
        }
        else if (lson.mn > rson.mn)
        {
            cur.mn = rson.mn, cur.mnc = rson.mnc;
            cur.mn2 = min(rson.mn2, lson.mn);
        }
        else
        {
            cur.mn = lson.mn, cur.mnc = lson.mnc + rson.mnc;
            cur.mn2 = min(rson.mn2, lson.mn2);
        }

        if (lson.mx > rson.mx)
        {
            cur.mx = lson.mx, cur.mxc = lson.mxc;
            cur.mx2 = max(rson.mx, lson.mx2);
        }
        else if (lson.mx < rson.mx)
        {
            cur.mx = rson.mx, cur.mxc = rson.mxc;
            cur.mx2 = max(rson.mx2, lson.mx);
        }
        else
        {
            cur.mx = lson.mx, cur.mxc = lson.mxc + rson.mxc;
            cur.mx2 = max(rson.mx2, lson.mx2);
        }
    }

    void build(int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx <= _sz)
            {
            	// cerr << lx << ' ' << a[lx] << '\n';
                node[x].mx = node[x].mn = node[x].sum = a[lx];
                node[x].mxc = node[x].mnc = 1;
                node[x].mx2 = -inf, node[x].mn2 = inf;
            }
            return;
        }

        int mid = (lx + rx) >> 1;
        build(lson(x), lx, mid), build(rson(x), mid, rx);
        pushup(node[x], node[lson(x)], node[rson(x)]);
        // cerr << lx << ' ' << rx << ' ' << node[x].sum << '\n';
    }


    void update_ckmax(int x, ll v)
    {
        node[x].sum += (v - node[x].mn) * node[x].mnc;
        if (node[x].mx == node[x].mn)
            node[x].mx = v;
        else if (node[x].mx2 == node[x].mn)
            node[x].mx2 = v;
        node[x].mn = v;
    }

    void ckmax(int x, int lx, int rx, int l, int r, ll v)
    {
        if (rx <= l || r <= lx || node[x].mn >= v) return;
        if (l <= lx && rx <= r && node[x].mn2 > v)
        {
            update_ckmax(x, v);
            return;
        }

        int mid = (lx + rx) >> 1;
        pushdown(x, lx, rx, mid);
        if (l < mid) ckmax(lson(x), lx, mid, l, r, v);
        if (r > mid) ckmax(rson(x), mid, rx, l, r, v);
        pushup(node[x], node[lson(x)], node[rson(x)]);
    }

    ll query(int x, int lx, int rx, int l, int r)
    {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r)
        {
            return node[x].sum;
        }

        ll vl = 0, vr = 0;
        int mid = (lx + rx) >> 1;
        pushdown(x, lx, rx, mid);
        if (l < mid) vl = query(lson(x), lx, mid, l, r);
        if (r > mid) vr = query(rson(x), mid, rx, l, r);
        return vl + vr;
    }

    int query2(int x, int lx, int rx,ll val){
        if(rx - lx == 1)return lx;
        int mid = (lx + rx) >> 1;
        pushdown(x, lx, rx, mid);
        if(node[lson(x)].mn <= val)return query2(lson(x),lx,mid,val);
        else if(node[rson(x)].mn <= val) return query2(rson(x),mid,rx,val);
        else return -1;
    }

    int query3(int x, int lx, int rx,ll val){  
        if(rx - lx == 1)return lx;
        // assert(rx - lx > 1);
        // cerr << lx << ' ' << rx << ' ' << node[lson(x)].sum << ' ' << node[rson(x)].mx << ' ' << val << '\n';
        int mid = (lx + rx) >> 1;
        pushdown(x, lx, rx, mid);
        if(node[lson(x)].sum > val)return query3(lson(x),lx,mid,val);
        else return query3(rson(x),mid,rx,val-node[lson(x)].sum);
    }


};

int main(){
	fast
	cin>>n>>q;
	segtree tree(n);
	for(int i=0;i<n;i++)cin>>a[i+1];
	tree.build(1,1,n+1);
	for(int i=0;i<q;i++){
		ll t,x,y;
		cin>>t>>x>>y;
		if(t==1){//update
			tree.ckmax(1,1,n+1,1,x+1,y);
		}else if(t==2){
			ll ans = 0;
			ll at = x;
			while(at<=n){
                ll to;
                if(tree.query(1,1,n+1,n,n+1) > y)break;
				else to=tree.query2(1,1,n+1,y);
                to = max(to , at);
                // cerr << at << ' ' << to << '\n';
				at = to;
                if(tree.query(1,1,n+1,at,n+1) <= y)to = n;
				else to = tree.query3(1,1,n+1,y + tree.query(1,1,n+1,1,at)) - 1;
                // cerr << at << ' ' << to << '\n';
				if(to < at)break;  
				ans += to-at+1;
				y -= tree.query(1,1,n+1,at,to+1);
                // break;
				// cerr << at << ' ' << to << ' ' << tree.query(1,1,n+1,at,to+1) << '\n';

				at = to+1;
			}
			cout << ans << '\n';
		}
	}
}