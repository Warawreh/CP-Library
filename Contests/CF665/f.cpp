#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	node *l,*r;
	ll val;
	node(){
		l = r = NULL;
		val = 0;
	}
	void marge(){
		ll a = 0,b=0;
		if(l != NULL)a = l->val;
		if(r != NULL)b = r->val;
		val = a+b;
	}
};

int TO;
node *head;
int f[111];
int n,q;

void update_range(int at,ll val,node *&n = head,int s = 1,int e = TO,int lvl = ::n){
	if(n == NULL)n = new node();
	if(s > at || e < at)return;
	if(s == e){
		n->val = val;
		return;
	}
	if(f[lvl]){
		int nat = at;
		if(nat <= (s+e)/2){
			nat += (e-s+1)/2;
		}else{
			nat -= (e-s+1)/2;
		}
		update_range(nat,val,n->l,s,(s+e)/2,lvl-1);
		update_range(nat,val,n->r,(s+e)/2 + 1,e,lvl-1);
	}else{
		update_range(at,val,n->l,s,(s+e)/2,lvl-1);
		update_range(at,val,n->r,(s+e)/2 + 1,e,lvl-1);
	}
	n->marge();
}

ll get(int l,int r,node *& n = head,int s = 1,int e = TO,int lvl = ::n){
	// debug(s,e,l,r);
	if(n == NULL)return 0;
	if(s > r || e < l || l > r)return 0LL;
	if(s >= l && e <= r)return n->val;
	ll a=0,b=0;
	if(f[lvl]){
		if(l <= (s+e)/2 && r <= (s+e)/2){
			l += (e-s+1)/2;
			r += (e-s+1)/2;
			a = get(l , r , n->r ,(s+e) / 2+1,e,lvl-1);
		}else if(l > (s+e)/2 && r > (s+e)/2){
			l -= (e-s+1)/2;
			r -= (e-s+1)/2;
			a = get(l , r , n->l , s , (s+e) / 2,lvl-1);
		}else{
			int nl = l,nr = r;	
			int dif1 = max(0,l - s);
			int dif2 = max(0,e - r);
			// cerr << lvl << ' ' << s << ' ' << e << ' ' << l << ' ' << r << ' ' << nl << ' ' << nr << '\n';
			// debug(s,e,l,r,dif1,dif2);
			if(dif2 >= 0){
				a = get(s, (s+e)/2 - dif2 , n->l , s , (s+e) / 2,lvl-1);
			}
			if(dif1 >= 0){
				b = get( (s+e)/2 + dif1 + 1, e , n->r , (s+e)/2+1 , e,lvl-1);
			}
		}
	}else{
		a = get(l , r , n->l , s , (s+e) / 2,lvl-1);
		b = get(l , r , n->r , (s+e)/2+1 , e,lvl-1);
	}
	// cerr << f[lvl] << '\n';
	// cerr << lvl << ' ' << l << ' ' << r << ' ' << a << ' ' << b << '\n';
	return a + b;
}

int main(){
	fast
	cin>>n>>q;

	TO = (1 << n);
	head = new node();
	for(int i=1;i<=(1<<n);i++){
		int a;
		cin>>a;
		update_range(i,a);
	}
	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		if(t == 1){
			int b,c;
			cin>>b>>c;
			update_range(b,c);
		}else if(t == 2){
			int k;
			cin>>k;
			for(int j=0;j<=k;j++)f[j] ^= 1;
		}else if(t == 3){
			int k;
			cin>>k;
			f[k+1] ^= 1;
		}else if(t == 4){
			int l,r;
			cin>>l>>r;
			cout << get(l,r) << '\n';
		}else assert(0);
		// for(int j=0;j<=n;j++)cerr << f[j] << ' ';
		// cerr << '\n';
		// cerr << t << " : ";
		// for(int j=1;j<=(1<<n);j++){
		// 	cerr << get(j,j) << ' ';
		// }
		// cerr << '\n';
	}
}