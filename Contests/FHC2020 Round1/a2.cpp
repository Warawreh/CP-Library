#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

ll A(ll &x,ll a){
	x += a;
	if(x < 0)x+=mod;
	if(x >= mod)x-=mod;
	return x;
}

struct node{
	node *l,*r;
	ll lazy,val;
	int sz;
	node(){
		l = r = NULL;
		lazy = val = 0;
	}
	void pro(){
		if(lazy)val = sz;
		if(l == NULL){
			l = new node();
			l->sz = (sz+1)/2;
			// cerr << sz << ' ' << l->sz << '\n';
		}
		l->lazy |= lazy;
		if(r == NULL){
			r = new node();
			r->sz = sz - l->sz;
		}
		r->lazy |= lazy;
		lazy = 0;
	}
	void marge(node *lhs,node *rhs){
		// sz = lhs->sz + rhs->sz;
		val = lhs->val + rhs->val;
	}
};

const int TO = 5e5;
node *head;

void update_range(int l,int r,ll val,node *&n = head,int s = 1,int e = TO){
	if(n == NULL){
		n = new node();
		n->sz = e - s + 1;
	}
	n->pro();
	if(s > r || e < l || l > r)return;
	if(s >= l && e <= r){
		n->lazy = val;
		n->pro();
		return;
	}
	update_range(l , r , val , n->l , s , (s+e)/2);
	update_range(l , r , val , n->r , (s+e)/2+1 , e);
	n->marge(n->l,n->r);
}

ll get(int l,int r,node *& n = head,int s = 1,int e = TO){
	if(l <= 0)return 0;
	if(n == NULL)return 0;
	n->pro();
	if(s > r || e < l || l > r)return 0LL;
	if(s >= l && e <= r)return n->val;
	ll a = get(l , r , n->l , s , (s+e) / 2);
	ll b = get(l , r , n->r , (s+e)/2+1 , e);
	return a + b;
}

void solve(){
	head = new node();
	head->sz = TO;
	ll n,k;
	cin>>n>>k;
	vector<ll> l(k),w(k),h(k);
	for(ll &i : l)cin>>i;
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=k;i<n;i++){
			ll val = (a * l[i-2])%d;
			val = (val + b * l[i-1])%d;
			val = (val + c)%d;
			l.push_back(val + 1);
		}
	}
	for(ll &i : w)cin>>i;
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=k;i<n;i++){
			ll val = (a * w[i-2])%d;
			val = (val + b * w[i-1])%d;
			val = (val + c)%d;
			w.push_back(val + 1);
		}
	}
	for(ll &i : h)cin>>i;
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=k;i<n;i++){
			ll val = (a * h[i-2])%d;
			val = (val + b * h[i-1])%d;
			val = (val + c)%d;
			h.push_back(val + 1);
		}
	}

	ll ans = 1;
	ll p = 0;
	map<int,int> t;
	set<int> seg;
	for(int i=0;i<n;i++){
		A(p , (2 * h[i] + 2 * w[i])%mod);
		A(p , (-get(l[i] , l[i] + w[i] - 1) * 2));
		while(seg.size()){
			auto it = seg.upper_bound(l[i]);
			if(it == seg.end())break;
			if(*it >= l[i] + w[i])break;
			A(p,-h[i]);
			t[*it] = 0;
			seg.erase(it);
		}
		{
			auto it = seg.find(l[i]);
			if(it != seg.end()){
				// if(i == 2)cerr << t[*it] << '\n';
				if(t[l[i]] == 2){
					A(p,-h[i]);
					t[l[i]] = 0;
					seg.erase(it);
				}
			}
		}
		{
			auto it = seg.find(l[i] + w[i]);
			if(it != seg.end()){
				if(t[l[i] + w[i]] == 1){
					A(p,-h[i]);
					t[l[i] + w[i]] = 0;
					seg.erase(it);
				}
			}
		}
		// if(i == 3)cerr << p << '\n';
		if(get(l[i] - 1 , l[i]))A(p,-h[i]);
		else{
			t[l[i]] = 1;
			seg.insert(l[i]);
		}
		if(get(l[i] + w[i] - 1 , l[i] + w[i]))A(p,-h[i]);
		else{
			t[l[i] + w[i]] = 2;
			seg.insert(l[i] + w[i]);
		}
		update_range(l[i] , l[i] + w[i] - 1 , 1);
		// cerr << p << '\n';	
		assert(p >=0);
		ans = (ans * p)%mod;
	}

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}