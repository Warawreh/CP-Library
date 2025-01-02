#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
	 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5 + 10;

indexed_set seg[4*nax];
int n;

void update(int at,int val,int n=1,int s=1,int e = ::n){
	if(s > at || e < at)return;
	// cerr << n << ' ' << s << ' ' << e << ' ' << val << '\n';
	seg[n].insert(val);
	if(s == e)return;
	update(at,val,n+n,s,(s+e)/2);
	update(at,val,n+n+1,(s+e)/2+1,e);
}

int get(int l,int r,int n=1,int s=1,int e =::n){
	if(s > r || e < l || l > r)return 0;
	if(s >= l && e <= r){
		// cerr << n << ' ' << s << ' ' << e << '\n';
		// cerr << seg[n].size() << ' ' << seg[n].order_of_key(r+1) << '\n';
		return seg[n].size() - seg[n].order_of_key(r+1);
	}
	return get(l,r,n+n,s,(s+e)/2) + get(l,r,n+n+1,(s+e)/2+1,e);
}

int main(){
	fast
	cin>>n;
	vector<int> a(n+2),at(n+2,n+1),nxt(n+2,n+1);
	int o = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o += a[i] == 1;
		at[a[i]] = i;
	}
	for(int i=n;i>=1;i--){
		if(at[a[i]] == i){
			nxt[i] = n+1;
		}else{
			nxt[i] = at[a[i]];
			at[a[i]] = i;
		}
		if(a[i] == 1){
			update(i,nxt[i]);
		}
	}
	if(o == n){
		cout << 1 << '\n';
		return 0;
	}
	for(int i=2;i<=n+1;i++){
		int l = 1;
		int r = at[i];
		bool good = false;
		while(l <= n){
			// cerr << i << ' ' << l << ' ' << r << ": " << '\n';
			// get(l,r-1);
			// return 0;
			int x = get(l,r - 1);
			assert(x <= i - 1);
			if(x == i - 1){
				good = true;
				break;
			}
			// cerr << '\n';
			if(r > n)break;
			l = r + 1;
			r = nxt[r];
		}
		if(!good){
			cout << i << '\n';
			return 0;
		}
		r = at[i];
		while(r <= n){
			update(r,nxt[r]);
			r = nxt[r];
		}
	}
	cout << n+2 << '\n';
}