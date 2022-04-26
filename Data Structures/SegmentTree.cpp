/*
Name: Segment Tree
Description: Used to find queries on range and do updates
Time: O(NLogN) with small factor
Space: O(4N)
*/
struct SegTree{
    typedef ll T;
    int n;
    vector<T> seg,lazy;
    const T oo = 0;

    SegTree(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n);
    }

    T merge(T l, T r){
        return l + r;
    }

    void build(int n,int s,int e){
        if(s == e){
            seg[n] = s;
            return;
        }
        build(n+n, s, (s+e)/2);
        build(n+n+1, (s+e)/2+1, e);
        seg[n] = merge(seg[n+n] , seg[n+n+1]);

    }

    void pro(int n,int s,int e){
        seg[n] += lazy[n];
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
            seg[n] += val;
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