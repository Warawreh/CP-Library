/*
Name: Persistent Segment Tree (History SegTree) with compressed tree
Description: Find value of a position after applying only a perfix of updates
Time: O(N) to build an empty tree O(LogN) Update and Get
Space: O(4N)
*/

struct node{
    node *l;
    node *r;
    ll sum = 0;
    node(){
        l = r = nullptr;
        sum = 0;
    }
    node(int val){
        sum = val;
        l = r = nullptr;
    }
    node(node* a,node* b){
        l = a;
        r = b;
        sum = 0;
        if(l != nullptr)sum += l->sum;
        if(r != nullptr)sum += r->sum;
    }
};

struct PersistentSegTree{
    int TO;
    PersistentSegTree(int _n){
        TO = _n;
    }

    node* build (int s, int e) {
        if(s == e)return new node();
        return new node(build(s , (s+e)/2) , build((s+e)/2+1, e));
    }

    node* build(){
        return build(1,TO);
    }

    node* update(int at,int val, node *n,int s,int e){
        if(n == nullptr)n = new node();

        if(s == e)return new node(n->sum + val);
        
        if(at <= (s + e)/2){
            return new node( update(at , val, n->l, s , (s + e)/2 ) , n->r);
        }else{
            return new node( n->l , update(at , val, n->r, (s+e)/2 + 1 , e));
        }
    }


    ll get(int l,int r,node *n,int s,int e){
        if(s > r || e < l || l > r || n == nullptr)return 0;
        if(s >= l && e <= r)return n->sum;
        return get(l,r,n->l , s, (s+e)/2) + get(l,r,n->r,(s+e)/2+1,e);
    }

    node* update(int at,int val,node *n){
        return update(at , val, n, 1 , TO);
    }

    ll get(int l,int r,node *n){
        return get(l , r , n , 1 , TO);
    }

};
