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

struct MAX_BPM{
	vector<vector<int>> g;
	vector<int> seen,matched;
	int n,m;

	void init(int N,int M){
		n = N+1;
		m = M+1;
		g = vector<vector<int>> (n);
		seen = matched = vector<int> (m);	
	}

	bool bpm(int u){ 
		for(int v : g[u]){ 
			if (!seen[v]){
				seen[v] = true;
				if (matched[v] == -1 || bpm(matched[v])){
					matched[v] = u; 
					return true; 
				}
			}
		}
		return false; 
	}

	void maxBPM(){
		fill(matched.begin(),matched.end(),-1);
		int result = 0;
		for (int u=1;u<n; u++) {
			fill(seen.begin(),seen.end(),0);
			if (bpm(u))result++;
		}
		cout << (result == n-1 ? "YES\n" : "NO\n");
		
	}
};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m)),b(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
		}
	}
	MAX_BPM graph;
	graph.init(n,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool good = true;
			for(int x=0;x<m;x++){
				if(a[i][x] % b[j][x] != 0)good = false;
			}
			if(good){
				graph.g[i+1].push_back(j+1);
			}
		}
	}
	graph.maxBPM();
}

int main(){
	fast
	#ifndef LOCAL
		freopen("grids.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}