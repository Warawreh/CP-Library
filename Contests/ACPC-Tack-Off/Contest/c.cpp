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

void solve(){
	int n;
	cin>>n;
	vector<int> num(33,-1);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		int b = __builtin_popcount(a);
		if(num[b] == -1)num[b] = 0;
		num[b] ^= a;
	}
	while(1){
		vector<int> nxt(33,-1);
		for(int i=0;i<33;i++){
			if(num[i] == -1)continue;
			int a = num[i];
			int b = __builtin_popcount(a);
			if(nxt[b] == -1)nxt[b] = 0;
			nxt[b] ^= a;
		}
		if(nxt == num)break;
		num = nxt;
	}
	vector<int> ans;
	for(int i=0;i<33;i++){
		if(num[i] != -1)ans.push_back(num[i]);
	}
	sort(all(ans));
	for(int i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main(){
	fast
	#ifndef LOCAL
		freopen("reduced.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}