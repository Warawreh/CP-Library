/*
Name: Compressed Segment Tree
Description: Segment tree but only create nodes for used indexes to save memory
Time: O(NLogN) with small factor
Space: O(4N)
*/

struct node{
   node *l,*r;
   ll lazy,val;
   int sz;
   node(){
      l = r = NULL;
      sz = 1;
      lazy = val = 0;
   }
   void pro(){
      val += lazy * sz;
      if(l != NULL)l->lazy += lazy;
      if(r != NULL)r->lazy += lazy;
      lazy = 0;
   }
   void marge(node *lhs,node *rhs){
      sz = lhs->sz + rhs->sz;
      val = lhs->val + rhs->val;
   }
};

struct CompressedSegTree{
   
   node *head;
   int n;
   void init(int _n){
      n = _n;
      head = new node();
   }

   void update_range(int l,int r,ll val){
      update_range(l,r,val,head,1,n);
   }

   ll get(int l,int r){
      return get(l,r,head,1,n);
   }

   void update_range(int l,int r,ll val,node *&n,int s,int e){
      if(n == NULL)n = new node();
      n->pro();
      if(s > r || e < l || l > r)return;
      if(s >= l && e <= r){
         n->lazy += val;
         n->pro();
         return;
      }
      update_range(l , r , val , n->l , s , (s+e)/2);
      update_range(l , r , val , n->r , (s+e)/2+1 , e);
      n->marge(n->l,n->r);
   }

   ll get(int l,int r,node *& n,int s,int e){
      if(n == NULL)return 0;
      n->pro();
      if(s > r || e < l || l > r)return 0LL;
      if(s >= l && e <= r)return n->val;
      ll a = get(l , r , n->l , s , (s+e) / 2);
      ll b = get(l , r , n->r , (s+e)/2+1 , e);
      return a + b;
   }

};

const int TO = 5e5;
SegTree<TO> t;
