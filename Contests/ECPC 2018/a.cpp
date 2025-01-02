#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > dout & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, dout&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct dout {
#ifdef LOCAL
~dout() { cerr << endl; }
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
#define esem(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll x,y,m,k;
ll solve(ll sz1){

	ll val = 0;	
	{
		ll sz = x + y - 1; 
		val = (1LL << sz) % m;
		x--;
	}

	ll sz = sz1;
	ll seg = (1LL << sz);
	vector<vector<ll>> r(seg,vector<ll>(x+1,0));
	for(int i=0;i<seg;i++){
		int o = __builtin_popcountll(i);
		if(o > x)continue;
		ll cur = i % m;
		r[cur][o]++;
	}

	for(int i=1;i<seg;i++){
		for(int j=0;j<=x;j++){
			r[i][j] += r[i-1][j];
		}
	}

	ll ans = 0;
	{
		ll sz = x + y - sz1;
		ll seg = (1LL << sz);
		for(int i=0;i<seg;i++){
			int o = __builtin_popcountll(i);
			if(o > x)continue;
			ll cur = ((i * seg)%m + val)%m;

			int fr = k - cur;
			int to = m - cur;

			fr = max(0 , fr);
			to = max(0 , to);

			if(cur == 0)to = m;

			if(fr > r.size())continue;
			if(to > r.size())to = r.size();
			// if(fr > to)
			// 	dout() << cur << ' ' << fr << ' ' << to << ' ' << r.size();
			assert(fr <= to);


			if(cur >= k)fr = 0;

			int need = x - o;
			ans += (to ? r[to - 1][need] : 0LL) - (fr ? r[fr - 1][need] : 0LL);
			if(ans < 0){
				cerr << fr << ' ' << to << '\n';
			}
		}
	}
	return ans;
}

void solve(){
	
	cin>>x>>y>>m>>k;

	ll ans = solve((x + y)/2);

	if((x + y) % 2 == 1){
		ans += solve((x + y + 1)/2);
	}

	cout << ans << '\n';
}

int main(){
	fast
	freopen("zeros.in","r",stdin);	
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/