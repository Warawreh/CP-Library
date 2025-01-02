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

string S,tmp;
int k;
int dp[1010][4];

int calc(int i,int a){
	if(a > k)return 1e9;
	if(i+a == tmp.size() && i == S.size())return a;
	if(i+a == tmp.size())return 1e9;
	int &ret = dp[i][a];
	if(ret != -1)return ret;
	ret = 1e9;
	if(i < S.size() && S[i] == tmp[i + a]){
		ret = min(ret , calc(i + 1 , a));
	}
	ret = min(ret , min(1 + calc(i + 1,a),calc(i,a+1)));
	return ret;
}


void solve(){
	int n;
	cin>>n;
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int q;
	cin>>q;
	while(q--){
		cin>>S>>k;
		vector<int> ans;
		for(int i=0;i<n;i++){
			memset(dp,-1,sizeof(dp));
			if(s[i].size() > S.size() + k || S.size() > s[i].size())continue;
			tmp = s[i];
			if(calc(0,0) <= k){
				ans.push_back(i);
			}
		}
		if(ans.empty())cout << -1 << '\n';
		else{
			for(int i : ans)
				cout << i << ' ';
			cout << '\n';
		}
	}
}

int main(){
	fast
	#ifndef LOCAL
		freopen("corrector.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}