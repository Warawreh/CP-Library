#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LEN = 1e6;
ll seg[4*LEN] , lazy[4*LEN];
int n;

void pro(int n,int s,int e){
	seg[n] = seg[n] + lazy[n];
	if(s != e){
		lazy[n+n] += lazy[n];
		lazy[n+n+1] += lazy[n];
	}
	lazy[n] = 0;
}

void update_range(int l,int r,ll val,int n = 1,int s = 1,int e = ::n){
	pro(n,s,e);
	if(s > r || e < l || l > r)return;
	if(s >= l && e <= r){
		lazy[n] += val;
		pro(n,s,e);
		return;
	}
	update_range(l , r , val , n+n , s , (s+e)/2);
	update_range(l , r , val , n+n+1 , (s+e)/2+1 , e);
	ll a = seg[n+n];
	ll b = seg[n+n+1];
	seg[n] = min(a,b);
}

ll get(int l,int r,int n = 1,int s = 1,int e = ::n){
	pro(n,s,e);
	if(s > r || e < l || l > r)return 1e18;
	if(s >= l && e <= r)return seg[n];
	ll a = get(l , r , n+n , s , (s+e) / 2);
	ll b = get(l , r , n+n+1 , (s+e)/2+1 , e);
	return min(a,b);
}

int main(){
	fast
	cin>>n;
	int g = n%2;
	ll sum = 0;
	vector<ll> a(n);
	for(int i=0;i<(n+1)/2;i++){
		cin>>a[i];
		sum += a[i];
	}
	ll x;
	cin>>x;
	int rest = n/2;
	n = n - rest;
	for(int i=0;i<n;i++){
		update_range(i+1,i+1,sum);
		sum += x;
		sum -= a[i];
	}
	int k = n;
	if(g){
		if(get(1,n) > 0){
			cout << k << '\n';
			return 0;
		}
	}
	for(int i=0;i<rest;i++){
		k++;
		update_range(1,n-i-g,x);
		// cerr << n-i << ' ' << x << ' ' << get(1,n-i) << '\n';
		if(get(1,n-i-g) > 0){
			cout << k << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}