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


void solve(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	vector<int> a;
	bool blocked = 0;
	vector<vector<vector<int>>> at(k+1,vector<vector<int>>(k)),blk(k+1,vector<vector<int>>(k));
	vector<int> lst(k+1,-1);	

	s = s + s;

	int mx = 0;
	for(int i=0;i<n+n;i++){
		if(i && s[i] == '#' && s[i-1] == '#')blocked = 1;
		if(s[i] == '#'){
			a.push_back(i);
			for(int x=1;x<=k;x++){
				at[x][i % x].push_back(i);
			}
			if(i < n)mx = i;
		}
	}

	for(int x=1;x<=k;x++){
		for(int y=0;y<x;y++){
			for(int i=1;i<a.size();i++){
				int pos = (int)(a[i-1]/x) * x + y;
				if(pos >= a[i-1])pos -= x;
				assert(pos < a[i-1]);
				if(pos + x >= a[i]){
					blk[x][y].push_back(a[i-1]);
				}
			}
		}
	}


	for(int i=0;i<n;i++){
		if(s[i] == '#'){
			mx = i + n;
			cout << 0 << ' ';
		}else{
			if(blocked){
				cout << -1 << ' ';
				continue;
			}


			int x = k;
			int to = mx;
			int p = i;
			int jump = 0;

			for(x=k;x>=1;x--){
				if(p > to)break;
				int far = to + 1;
				// if(i == 2)dout() << x << ' ' << p << ' ' << far;

				{//same position 
					int mdd = p % x;

					int id = lower_bound(all(at[x][mdd]) , p) - at[x][mdd].begin();

					if(id < at[x][mdd].size()){
						id = at[x][mdd][id];
						assert(id != p);
						far = min(far , id - x);
					}
				}

				{//two in same block
					int mdd = p % x;

					int id = lower_bound(all(blk[x][mdd]) , p) - blk[x][mdd].begin();

					if(id < blk[x][mdd].size()){
						id = blk[x][mdd][id];
						int pos = (int)(id / x) * x + mdd;
						if(pos >= id)pos -= x;
						far = min(far , pos);
					}
				}

				jump += (far - p + x - 1) / x;	
				p = far;
			}
			// dout() << i;

			// if(i == 9)dout() << x << ' ' << p << ' ' << to;

			if(x == 0 && p < to)cout << -1 << ' ';
			else if(p >= to)cout << jump << ' ';
			else cout << jump + (to - p)/x + 1 << ' ';
		}
	}
	cout << '\n';
}

int main(){
   fast
   freopen("jumps.in","r",stdin);
   int t;
   cin>>t;
   while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/