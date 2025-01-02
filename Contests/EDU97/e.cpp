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
	int lazy,val;
	node(){
		l = r = NULL;
		lazy = val = 0;
	}
	void pro(){
		if(lazy == -1)val = 0;
		else val = max(val , lazy);
		if(l != NULL){
			if(lazy == -1)l->lazy = -1;
			else l->lazy = max(lazy , l->lazy);
		}
		if(r != NULL){
			if(lazy == -1)r->lazy = -1;
			else r->lazy = max(lazy , r->lazy);
		}
		lazy = 0;
	}
	void marge(node *lhs,node *rhs){
		val = max(lhs->val , rhs->val);
	}
};

const int TO = 5e5;
node *head;

void update_range(int l,int r,int val,node *&n = head,int s = 1,int e = TO){
	if(n == NULL)n = new node();
	n->pro();
	if(s > r || e < l || l > r)return;
	if(s >= l && e <= r){
		if(val == -1)n->lazy = -1;
		else n->lazy = max(n->lazy , val);
		n->pro();
		return;
	}
	update_range(l , r , val , n->l , s , (s+e)/2);
	update_range(l , r , val , n->r , (s+e)/2+1 , e);
	n->marge(n->l,n->r);
}

int get(int l,int r,node *& n = head,int s = 1,int e = TO){
	if(n == NULL)return 0;
	n->pro();
	if(s > r || e < l || l > r)return 0LL;
	if(s >= l && e <= r)return n->val;
	int a = get(l , r , n->l , s , (s+e) / 2);
	int b = get(l , r , n->r , (s+e)/2+1 , e);
	return max(a , b);
}

int main(){
	fast
	int n,k;
	cin>>n>>k;
	vector<int> a(n),bad(n);
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v.push_back(a[i] - i + n);
	}
	sort(all(v));
	int lst = -1;
	vector<int> x;
	for(int i=0;i<k;i++){
		int b;
		cin>>b;
		bad[--b] = 1;
		x.push_back(b);
		if(lst != -1){
			if(a[b] - a[lst] < b - lst){
				cout << -1 << '\n';
				return 0;
			}
		}
		lst = b;
	}
	x.push_back(-1e9);
	x.push_back(1e9);
	sort(all(x));
	int at = 1;
	head = new node();
	int p = 0;
	int cnt = 0,len = 0;
	for(int i=0;i<n;i++){
		if(bad[i]){
			cnt += len;
			// for(int j=p;j<i;j++){
			// 	update_range(a[j] - j + n , a[j] - j + n , -1);
			// }
			// p = i + 1;
			head = new node();
			len = 0;
			at++;
			continue;
		}
		if((x[at] < n && a[x[at]] - a[i] < x[at] - i) || (at - 1 > 0 && a[i] - a[x[at - 1]] < i - x[at - 1]))
			continue;
		int at = lower_bound(all(v),a[i] - i + n) - v.begin();
		int val = 1 + get(1 , at + 1);
		// cerr << a[i] - i + n << ' ' << val << ' ' << at << '\n';
		update_range(at + 1 , at + 1 , val);
		len = max(len , val);

	}
	cnt += len;
	cout << n - cnt - k << '\n';
}