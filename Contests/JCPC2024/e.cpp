#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

struct SEGTREE{
    ll n;
    vector<ll> seg, lazy;
    const ll oo = -1e18;

    SEGTREE(ll _n){
        n = _n;
        seg = lazy = vector<ll>(4*n);
    }   

    ll merge(ll l, ll r){
        return max(l, r);
    }

    void build(ll n,ll s,ll e,vector<ll> &val){
        if(s == e){
            seg[n] = val[s - 1];
            return;
        }
        build(n+n, s, (s+e)/2, val);
        build(n + n + 1, (s+e)/2+1,e, val);
        seg[n] = merge(seg[n+n], seg[n+n+1]);
    }

    void pro(ll n,ll s,ll e){
        seg[n] += lazy[n];
        if(s != e){
            lazy[n+n] += lazy[n];
            lazy[n+n+1] += lazy[n];
        }
        lazy[n] = 0;
    }

    void update(ll l,ll r,ll val, ll n,ll s,ll e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] += val;
            pro(n,s,e);
            return;
        }
        update(l,r,val,n+n, s, (s+e)/2);
        update(l,r,val,n + n + 1, (s+e)/2+1,e);

        seg[n] = merge(seg[n+n], seg[n+n+1]);
    }

    ll get(ll l,ll r,ll n,ll s,ll e){
        pro(n,s,e);
        if(s >r || e < l|| l > r)return oo;
        if(s >= l && e <= r){
            return seg[n];
        }
        return merge(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
    }

    void update(ll l, ll r, ll val){
        update(l,r,val,1,1,n);
    }

    void update(ll at, ll val){
        update(at,at,val,1,1,n);
    }

    void build(vector<ll> &val){
        build(1,1,n,val);
    }

    ll get(ll l,ll r){
        return get(l, r,1,1,n);
    }
};

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n), b(n), c(n);
    vector<ll> pre(n);

    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
        cin>>b[i];
        c[i] = b[i] - a[i];
        pre[i] = c[i] + (i ? pre[i-1] : 0LL);
    }

    SEGTREE tree(n);
    tree.build(pre);

    vector<pair<ll,ll>> st;
    ll bSum = 0;
    for(ll i=n-1;i>n-k;i--)bSum += b[i];

    ll ans = -1e18;
    for(ll i=n-k;i>=0;i--){
        bSum += b[i];

        while(st.size() && bSum >= st.back().first){
            ll bef = st.back().second;
            ll val = st.back().first;
            st.pop_back();
            ll too = n;
            if(st.size())too = st.back().second - 1;
            tree.update(bef, too, val);
        }
        ll to = n;
        if(st.size())to = st.back().second - 1;
        // cerr << i + 1 << ' ' << to << ' ' << bSum << '\n';
        st.push_back({bSum, i+k});
        tree.update(i+k, to, -bSum);
        // cerr << tree.get(i+k, n) << ' ' << tree.get(i+k, n) - (i ? pre[i-1] : 0LL) << '\n';

        ans = max(ans, tree.get(i+k, n) - (i ? pre[i-1] : 0LL));

        bSum -= b[i + k - 1];
    }

    cout << ans << '\n';
}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}
