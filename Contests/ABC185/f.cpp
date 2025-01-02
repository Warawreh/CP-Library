#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 3e5 + 10;
int seg[4*nax];
int n;

void update(int at,int val,int n=1,int s = 1,int e = ::n){
	if(s > at || e < at)return;
	if(s == e){
		seg[n] ^= val;
		return;
	}
	update(at,val,n+n,s,(s+e)/2);
	update(at,val,n+n+1,(s+e)/2+1,e);
	seg[n] = seg[n+n] ^ seg[n+n+1];
}

int get(int l,int r,int n=1,int s=1,int e =::n){
	if(s > r || e < l || l > r)return 0;
	if(s >= l && e <= r)return seg[n];
	return get(l,r,n+n,s,(s+e)/2) ^ get(l,r,n+n+1,(s+e)/2+1,e);
}

int main(){
	fast
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		update(i+1,a);
	}
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t == 1)update(x,y);
		else cout << get(x,y) << '\n';
	}
}