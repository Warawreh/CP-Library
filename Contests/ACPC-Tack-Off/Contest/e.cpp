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

ld S(ld a){return a*a;}

ld dist(ld x0,ld y0,ld x1,ld y1,ld x2,ld y2){
	double l = S(x1 - x2) + S(y1-y2);
	if(l == 0)return S(x1 - x0) + S(y1 - y0);
	double t = ((x0 - x1) * (x2 - x1) + (y0 - y1) * (y2 - y1)) / l;
	t = max(0.0,min(1.0,t));
	double x = x1 + t * (x2 - x1);
	double y = y1 + t * (y2 - y1);
	double dis = S(x0 - x) + S(y0 - y);
	return dis;
}

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
	}
	int x,y;
	cin>>x>>y;
	ld ans = 1e18;
	for(int i=0;i<n;i++){
		ans = min(ans , dist(x,y,p[i].first,p[i].second,p[(i+1)%n].first,p[(i+1)%n].second));
	}
	cout << sqrt(ans) << '\n';
}

int main(){
	fast
	#ifndef LOCAL
		freopen("circle.in","r",stdin);
	#endif
	cout << setprecision(12) << fixed;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}