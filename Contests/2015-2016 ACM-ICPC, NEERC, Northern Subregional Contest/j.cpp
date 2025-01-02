#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

ll n,t;
vector<int> p;
vector<ll> cost;

const int LEN = 5e4 + 10;

ll seg[4*LEN] , lazy[4*LEN];

void pro(int n,int s,int e){
	seg[n] += lazy[n];
	if(s != e){
		lazy[n+n] += lazy[n];
		lazy[n+n+1] += lazy[n];
	}
	lazy[n] = 0;
}

void update(int l,int r,ll val,int n=1,int s=1,int e=::n){
	pro(n,s,e);
	if(s > r || e < l || l > r)return;
	if(s >= l && e <= r){
		lazy[n] += val;
		pro(n,s,e);
		return;
	}
	update(l,r,val,n+n,s,(s+e)/2);
	update(l,r,val,n+n+1,(s+e)/2+1,e);
	seg[n] = min(seg[n+n] ,seg[n+n+1]);
}

ll get(int l,int r,int n=1,int s=1,int e = ::n){
	pro(n,s,e);
	if(s > r || e < l || l > r)return 1e18;
	if(s >= l && e <= r)return seg[n];
	ll a = get(l,r,n+n,s,(s+e)/2);
	ll b = get(l,r,n+n+1,(s+e)/2+1,e);
	return min(a,b);
}

bool check(int md){
	for(int i=0;i<4*LEN;i++)seg[i] = lazy[i] = 0;
	vector<ll> dp(n+1,1e18);
	for(int i=n-1;i>=1;i--){
		update(i+1,n,1);
		dp[i] = cost[i] + get(i+1, min(n,i+md+0ll));
		update(i,i,dp[i]);
	}
	// cout << md << ' ' << dp[1] << '\n';
	return dp[1] <= t;
}

int main(){
	freopen("journey.in" , "r" , stdin);
	freopen("journey.out" , "w" , stdout);
	cin>>n>>t;
	p = vector<int> (n+1);
	cost = vector<ll> (n+1);
	for(int i=1;i<=n-1;i++)cin>>p[i];
	for(int i=n-2;i>=1;i--)p[i] = min(p[i] , p[i+1]);
	for(int i=2;i<=n-1;i++)cin>>cost[i];
	// for(int i=1;i<=n-1;i++)cout << p[i] << ' ';
	// cout << '\n';
	// cout << check(3) << '\n';
	int md,lo=1,hi =n-1,at =0;
	while(lo <= hi){
		md = (lo + hi)/2;
		if(check(md)){
			hi = md-1;
			at = md;
		}else lo = md+1;
	}
	cout << p[at] << '\n';
}