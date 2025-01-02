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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void solve(){
	int n,m,q;
	int x,y;
	char sd;
	int d;
	cin>>n>>m>>q>>x>>y>>sd;

	if(sd == 'U')d=0;
	if(sd == 'R')d=1;
	if(sd == 'D')d=2;
	if(sd == 'L')d=3;
	x--;y--;

	vector<string> g(n);
	for(int i=0;i<n;i++)cin>>g[i];

	vector<vector<vector<int>>> rotTo(n,vector<vector<int>>(m,vector<int>(4,0)));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j] == '#')continue;
			for(int dir=0;dir<4;dir++){

				for(int add=0;add<4;add++){
					int at = (dir + add)%4;
					int r = i + dx[at];
					int c = j + dy[at];
					if(g[r][c] == '.'){
						rotTo[i][j][dir] = at;
						break;
					}
				}

			}
		}
	}

	int rotate=0,forward=0;
	int ans = 0;
	int st = 0;

	for(int Q=0;Q<q;Q++){
		char op;
		cin>>op;

		if(op == 'R'){
			if(forward){
				if(st == 0)ans++;
				st = 1;
			}
			forward = 0;
			rotate++;
		}else{
			int distance;
			cin>>distance;
			if(rotate){
				rotate %= 4;
				int dist = rotTo[x][y][(rotate + d)%4];
				for(int i=0;i<=rotate;i++){
					if(rotTo[x][y][(d + i)%4] == dist){
						ans+=i;
						if(i)st = 0;
						break;
					}
				}
				d = dist;
			}
			rotate = 0;

			for(int i=0;i<distance;i++){
				int cur = rotTo[x][y][d];
				x += dx[cur];
				y += dy[cur];
				d = cur;
			}

			forward+=distance;
		}

		// dout() << x << ' ' << y << ' ' << d;
	}
	if(forward){
		if(st == 0)ans++;
	}

	g.clear();
	rotTo.clear();

	cout << ans << '\n';
}

int main(){
   fast
   freopen("reduce.in","r",stdin);

   int t;
   cin>>t;
   while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/