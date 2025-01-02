#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct line{
	ll a,b;
	line(){}
	line(ll _a,ll _b){a = _a;b=_b;}
	ll val(ll at){
		at -= (1e5 + 1);
		return a*at + b;
	}
};


struct node{
	node *l,*r;
	line cur;
	node(){
		l = r = NULL;
		cur = line(0,1e18);
	}
};

struct LiChaoTree{
	node *head = new node();
	const int TO = 2e5+1;

	bool check(ll a,ll b){return (a<b?1:0);}
	void insertLine(line val,node *&n,int s,int e){
		if(n == NULL){
			n = new node();
			n->cur = val;
		}else{
			int md = (s + e)/2;
			bool mid = check(val.val(md) , n->cur.val(md));
			bool left = check(val.val(s) , n->cur.val(s));

			if(mid)swap(n->cur , val);

			if(s == e)return;
			else if(left != mid)insertLine(val , n->l ,s , md);
			else insertLine(val , n->r,md + 1,e);
		}

	}

	ll get(int x,node *&n,int s,int e){
		if(n == NULL)return (ll)1e18;
		if(s == e)return n->cur.val(x);
		int md = (s + e)/2;
		if(x <= md)return min(n->cur.val(x) , get(x,n->l,s,md));
		else return min(n->cur.val(x) , get(x ,n->r,md+1,e));
	}

	void insertLine(line val){
		insertLine(val,head,1,TO);
	}

	ll get(int x){
		return get(x , head,1,TO);
	}
};

int main(){
    fast
    int n,q;
    cin>>n>>q;
    
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/