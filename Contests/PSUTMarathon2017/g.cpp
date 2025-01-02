#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
const int nax = 2e5 + 10;
int seg[3][nax*4];
int lazy[3][nax*4];

void update(int at,int t,int n=1,int s=1,int e =::n){
	if(s > at || e<at)return;
	if(s == e){
		seg[t][n] = 1;
		return;
	}
	update(at,t,n+n,s,(s+e)/2);
	update(at,t,n+n+1,(s+e)/2+1,e);
	seg[t][n] = seg[t][n+n] + seg[t][n+n+1];
}

void pro(int n,int t,int s,int e){
	if(lazy[t][n])
		seg[t][n] = 0;
	if(s != e){
		lazy[t][n+n] |= lazy[t][n];
		lazy[t][n+n+1] |= lazy[t][n];
	}
	lazy[t][n] = 0;
}

void update_r(int l,int r,int t,int n=1,int s=1,int e =::n){
	pro(n,t,s,e);
	if(s > r || e < l)return;
	if(s >= l && e <= r){
		lazy[t][n] = 1;
		pro(n,t,s,e);
		return;
	}
	if((s+e)/2 >= l)update_r(l,r,t,n+n,s,(s+e)/2);
	if((s+e)/2 + 1 <= r)update_r(l,r,t,n+n+1,(s+e)/2+1,e);
	seg[t][n] = seg[t][n+n] + seg[t][n+n+1];
}

int get(int l,int r,int t,int n=1,int s=1,int e=::n){
	pro(n,t,s,e);
	if(s > r || e < l)return 0;
	if(s >= l && e <= r)return seg[t][n];
	int a =0,b=0;
	if((s+e)/2 >= l)a = get(l,r,t,n+n,s,(s+e)/2);
	if((s+e)/2 + 1 <= r)b = get(l,r,t,n+n+1,(s+e)/2+1,e);
	return a + b;
}

int main(){
	
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	int r=0,g=0,b=0;
	for(int i=0;i<n;i++){
		if(s[i] == 'R'){
			r++;
			update(i+1,0);
		}
		if(s[i] == 'G'){
			g++;
			update(i+1,1);
		}
		if(s[i] == 'B'){
			b++;
			update(i+1,2);
		}
	}
	for(int i=0;i<m;i++){
		int L,R;
		scanf("%d%d",&L,&R);
		// cerr << get(L,R,0) << ' ' << get(L,R,1) << ' ' << get(L,R,2) << '\n';
		r = r + get(L,R,1) - get(L,R,0);
		g = g + get(L,R,2) - get(L,R,1);
		b = b + get(L,R,0) - get(L,R,2);
		update_r(L,R,0);
		update_r(L,R,1);
		update_r(L,R,2);
		printf("%d %d %d\n", r,g,b);
	}
}