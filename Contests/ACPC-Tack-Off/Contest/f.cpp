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
	string s;
	cin>>s;
	int n = s.size();

	vector<int> l(26);
	for(char c : s)l[c - 'a']++;
	int o = 0;
	for(int i=0;i<26;i++)o += (l[i]%2);
	if(o > n % 2){
		cout << "Impossible" << '\n';
		return;
	}

	int ans = 0;
	for(int i=0;i<n/2;i++){
		int left = i;
		int right = n-left-1;
		while(left < right){
			if(s[left] == s[right])break;
			else right--;
		}
		if(left == right){
			swap(s[i] , s[i+1]);
			ans++;
			i--;
			continue;
		}
		for (int j = right; j < n - left - 1; j++) { 
            swap(s[j], s[j + 1]); 
            ans++; 
        } 		
	}
	cout << ans << '\n';  
}

int main(){
	fast
	#ifndef LOCAL
		freopen("palindrome.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}