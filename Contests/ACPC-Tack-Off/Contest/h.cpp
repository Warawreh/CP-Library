#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

////////////Errichto Debug
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//////////////

const int nax = 1e6 + 10;
pair<int,int> mn[4*nax],mx[4*nax];
map<ll,int> dp;
int ans[nax];

void build(int n = 1,int s = 1,int e = nax-10){
	if(s == e){
		mn[n] = {ans[s] , s};
		mx[n] = {ans[s] , s};
		return;
	}
	build(n+n,s,(s+e)/2);
	build(n+n+1,(s+e)/2+1,e);
	mn[n] = min(mn[n+n] , mn[n+n+1]);
	mx[n] = max(mx[n+n] , mx[n+n+1]);
}

pair<int,int> getmn(int l,int r,int n=1,int s = 1,int e = nax-10){
	if(s > r || e < l || l > r)return {1e9,1e9};
	if(s >= l && e <= r)return mn[n];
	return min(getmn(l,r,n+n,s,(s+e)/2) , getmn(l,r,n+n+1,(s+e)/2+1,e));
}
pair<int,int> getmx(int l,int r,int n=1,int s = 1,int e = nax-10){
	if(s > r || e < l || l > r)return {0,0};
	if(s >= l && e <= r)return mx[n];
	return max(getmx(l,r,n+n,s,(s+e)/2) , getmx(l,r,n+n+1,(s+e)/2+1,e));
}

int calc(ll i){
	if(i == 1)return 0;
	if(dp[i] != 0)return dp[i];
	if(i % 2 == 1){
		return dp[i] = 1 + calc(3*i + 1);
	}else if(i % 2 == 0){
		return dp[i] = 1 + calc(i/2);
	}
	return 0;
}

void solve(){
	int l,r;
	cin>>l>>r;
	cout << getmn(l,r).second << ' ' << getmx(l,r).second << '\n';
}

int main(){
	fast
	#ifndef LOCAL
		freopen("minmax.in","r",stdin);
	#endif

	for(int i=1;i<nax;i++){
		ans[i] = calc(i);
	}

	build();
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}