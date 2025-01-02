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

ll a,b,c,d;

ll S(ll x){
	if(x < 0)return 0LL;
	return (x * (x + 1)/2 + (d-1) * (x - 1) * x/2 + (c - 1) * x + x);
}

ll get(int x){
	ll res = x*a;
	ll T = (x-1) * d + 1;
	ll bf= (T - 2 + d)/d;;
	ll af = max(0LL,(T - c - 2 + d)/d) + 1;
	bf = max(bf , 0LL);
	af = max(af , 0LL);

	debug() << imie(res);
	res -= c*b*max(0LL,af - 1);
	debug() << imie(res);
	debug() << imie(af) imie(bf);
	ll sum = S(bf) - S(af - 1);
	debug() << imie(sum) imie(T) imie(S(bf)) imie(S(af-1));
	ll outside = sum - (T) * (bf - af + 1);
	if(outside >= 0){
		sum = (bf - af + 1) * c - outside;
		res -= (sum) * b;

	}
	debug() << imie(sum) imie(outside);

	return res;
}

void solve(){
	cin>>a>>b>>c>>d;
	ll lo = 1,hi = 2e6,ans = 0;
	for(int it=0;it<63;it++){
		ll md1 = lo + (hi - lo)/3;
		ll md2 = hi - (hi - lo)/3;
		if(get(md1) > get(ans))ans = md1;
		if(get(md2) > get(ans))ans = md2;
		if(get(md1) >= get(md2)){
			hi = md2;
		}else{
			lo = md1;
		}
	}
	// cerr << ans << '\n';
	// cerr << get(ans) << ' ' << get(ans+1) << '\n';
	if(get(ans) < get(ans + 1)){
		cout << -1 << '\n';
	}else{
		assert(get(ans) >= 0);
		cout << get(ans) << '\n';
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}