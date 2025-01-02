#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int TO = 1e6;
ll seg[4*TO + 10];

void update(int at,int val,int n = 1,int s = 1,int e = ::TO){
	if(s > at || e < at)return;
	if(s == e){
		seg[n] += val;
		return;
	}
	update(at,val,n+n,s,(s+e)/2);
	update(at,val,n+n+1,(s+e)/2+1,e);
	seg[n] = seg[n+n] + seg[n+n+1];
}

ll get(int l,int r,int n = 1,int s = 1,int e = ::TO){
	if(s > r || e < l || l > r)return 0;
	if(s >= l && e <= r)return seg[n];
	return get(l,r,n+n,s,(s+e)/2) + get(l,r,n+n+1,(s+e)/2+1,e);
}

set<ll> st;
vector<int> a;

int get(int x){
	int at = upper_bound(all(a) , x) - a.begin();
	if(at == 0)return -1;
	return a[at-1];
}

int get2(int x){
	int at = upper_bound(all(a) , x) - a.begin();
	if(at == a.size())return (int)1e9;
	return a[at];
}

void build(int l,int r){
	if(l > r || get(l , r) == 0)return;
	
	int md = (l + r)/2;
	st.insert(get(l,r));
	// cerr << l << ' ' << r << ' ' << get(l,r) << '\n';
	if(l == r)return;
	// cerr << l << ' ' << r << ' ' << md << ' ' << get(md) << ' ' << get2(md) << '\n';
	build(l,get(md));
	build(get2(md),r);
}

void solve(){
	int n,p;
	cin>>n>>p;

	a = vector<int>(n);
	st.clear();
	for(int i=0;i<n;i++){
		cin>>a[i];
		update(a[i] , a[i]);
	}
	sort(all(a));
	// cerr << 1 << '\n';	
	build(a[0] , a.back());
	// cerr << 1 << '\n';

	for(int i=0;i<p;i++){
		int s;
		cin>>s;
		// cerr << st.find(s) << '\n';
		if(st.find(s) != st.end())cout << "Yes\n";
		else cout << "No\n";
	}

	for(int i=0;i<n;i++){
		update(a[i] , -a[i]);
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}