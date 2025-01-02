#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2e5 + 1;
ll seg[4*nax];
int mn[4*nax],lazy[4*nax];
int n,q;
int a[nax];

void pro2(int n, int s, int e, int val){
	seg[n] = (e - s + 1) * 1LL * val;
	mn[n] = val;
	lazy[n] = val;
}

void pro(int n,int s,int e){
	if(lazy[n] && s!=e){
		pro2(n+n,s,(s+e)/2,lazy[n]);
		pro2(n+n+1,(s+e)/2+1,e,lazy[n]);
		lazy[n] = 0;
	}	
}

void build(int n=1,int s=1,int e=::n){
	if(s == e){
		seg[n] = mn[n] = a[s];
		return;
	}
	build(n+n,s,(s+e)/2);
	build(n+n+1,(s+e)/2+1,e);
	seg[n] = seg[n+n] + seg[n+n+1];
	mn[n] = mn[n+n+1];
}

void update(int l,int r,int val,int n=1,int s=1,int e=::n){
	if(s > r || e < l || l > r)return;
	if(s >= l && e <= r){
		pro2(n,s,e,val);
		return;
	}
	pro(n,s,e);
	if((s+e)/2 >= l)update(l,r,val,n+n,s,(s+e)/2);
	if((s+e)/2+1 <= r)update(l,r,val,n+n+1,(s+e)/2+1,e);
	seg[n] = seg[n+n] + seg[n+n+1];
	mn[n] = min(mn[n+n] , mn[n+n+1]);
}

ll get(int l,int r,int n=1,int s = 1,int e = ::n){
	if(s > r || e < l || l > r)return 0;
	if(s>=l&&e<=r)return seg[n];
	pro(n,s,e);
	ll a=0,b=0;
	if((s+e)/2 >= l)a = get(l,r,n+n,s,(s+e)/2);
	if((s+e)/2+1 <= r)b = get(l,r,n+n+1,(s+e)/2+1,e);
	return a + b;
}

int get2(ll val,int n=1,int s=1,int e = ::n){
	if(s == e)return s + (mn[n] > val);
	pro(n,s,e);
	if(mn[n+n] <= val)return get2(val,n+n,s,(s+e)/2);
	else return get2(val,n+n+1,(s+e)/2+1,e);
	
}

int get3(ll val,int n=1,int s=1,int e = ::n){
	if(s == e)return s + (seg[n] <= val);
	pro(n,s,e);	
	if(seg[n+n] > val)return get3(val,n+n,s,(s+e)/2);
	else return get3(val-seg[n+n],n+n+1,(s+e)/2+1,e);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build();
	for(int i=0;i<q;i++){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){//update
			int fr=get2(y);
			if(fr <= x)update(fr,x,y);
		}else if(t==2){
			int ans = 0;
			int at = x;
			while(at<=n){
				int to=get2(y);
				at = max(to , at);
				to = get3(y + get(1,at-1)) - 1;
				// cerr << y + get(1,at-1) << ' ' << at << ' ' << to << '\n';
				ans += to-at+1;
				y -= get(at,to);

				at = to+1;
			}
			printf("%d\n", ans);
		}
	}
}