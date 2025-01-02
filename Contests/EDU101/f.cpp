#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int TO = 1e6 + 100;
ll seg[4*TO] , lazy[4*TO];
int n,k;

void pro(int n,int s,int e){
	seg[n] += (e - s + 1) * lazy[n];
	if(s != e){
		lazy[n+n] += lazy[n];
		lazy[n+n+1] += lazy[n];
	}
	lazy[n] = 0;
}

void update(int l,int r,int val,int n = 1,int s = 1,int e = ::TO){
	pro(n,s,e);
	if(s > r || e < l)return;
	if(s >= l && e <= r){
		// cerr << s << ' ' << e << ' ' << val << '\n';
		lazy[n] += val;
		pro(n,s,e);
		return;
	}
	update(l,r,val,n+n,s,(s+e)/2);
	update(l,r,val,n+n+1,(s+e)/2+1,e);
	seg[n] = seg[n+n] + seg[n+n+1];
}

int get(int k,int n = 1,int s = 1,int e = ::TO){
	pro(n,s,e);
	if(s == e){
		// cerr << ' ' << k << ' ' << seg[n] << '\n';
		return s;
	}
	pro(n+n,s,(s+e)/2);
	// cerr << k << ' ' << s << ' ' << e << ' ' << seg[n+n] << '\n';
	if(k <= seg[n+n]){
		return get(k,n+n,s,(s+e)/2);
	}else{
		return get(k-seg[n+n],n+n+1,(s+e)/2+1,e);
	}
}

int get2(int l,int r,int n = 1,int s = 1,int e = ::TO){
	pro(n,s,e);
	if(s > r || e < l)return 0;
	if(s >= l && e <= r)return seg[n];
	return get2(l,r,n+n,s,(s+e)/2) + get2(l,r,n+n+1,(s+e)/2+1,e);
}

int main(){
	fast
	cin>>n>>k;
	vector<int> l(n);
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(all(l));
	reverse(all(l));
	update(1,1,1);
	int ans = 1e9;
	ll cur = 1;
	for(int i=0;i<n;i++){
		int at = get(1);
		// cerr << '\n';
		update(at,at,-1);
		int len = (l[i] + 1) / 2 - 1;
		// if(i<100)cerr << at << ' ' << len << '\n';
		update(at + 2,at+2+len-1,2);
		if(l[i] % 2 == 0){
			update(at+2+len,at+2+len,1);
		}
		cur += l[i] - 2;
		if(cur >= k){
			ans = min(ans , get(k));
		}
		// if(i<100)cerr << get2(3,3) << '\n';
	}
	if(cur < k)cout << -1 << '\n';
	else cout << ans - 1 << '\n';
}