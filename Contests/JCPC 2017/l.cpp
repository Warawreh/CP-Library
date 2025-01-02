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

int dx[] = {1,-1,2,-2,2,-2,1,-1};
int dy[] = {2,2,1,1,-1,-1,-2,-2};

const int mod = 1e9 + 7;
const int nax = 502;
int dp[nax][3][5][5][7];
vector<string> g;
vector<pair<int,int>> k;
int n,m;
vector<int> bad;

int calc(int i,int d1,int d2,int d3,int d4){
  if(i == n)return 1;
  int &ret = dp[i][d1][d2][d3][d4];
  if(ret != -1)return ret;
  ret = 0;

  int r = k[i].first;
  int c = k[i].second;

  int st = 0;
  if(i + 2 > n)st+=2;
  if(i + 1 > n)st+=2;
  for(int x=st;x<8;x++){
    int nr = r + dx[x];
    int nc = c + dy[x];
    if(nc < 0)break;
    if(nr < 0 || nc < 0 || nr >= n || nc >= m || g[nr][nc] != '.' || bad[nr* m + nc] > 0)continue;

    bad[nr*m + nc]++;
    ret = (ret + calc(i+1,min(2,d2),min(4,d3),min(4,d4),min(6,x)));
    bad[nr*m + nc]--;
    if(ret >= mod)ret -= mod;
  }
  return ret;
}

void solve(){
  // cin>>n>>m;
  scanf("%d %d",&n,&m);
  g.clear();
  g.resize(n);
  k.clear();

  bad = vector<int>(n*m+1,0);
  for(int i=0;i<n;i++){ 
    char s[m];
    scanf("\n%s", s);
    // cin>>g[i];
    g[i] = s;
  }

  for(int j=0;j<m;j++)
    for(int i=0;i<n;i++)
      if(g[i][j] == '*')k.push_back({i,j});

  for(int i=0;i<n;i++)
    for(int a=0;a<3;a++)
      for(int b=0;b<5;b++)
        for(int c=0;c<5;c++)
          for(int d=0;d<7;d++)
            dp[i][a][b][c][d] = -1;

  printf("%d\n", calc(0,2,4,4,6));
  // cout <<  << '\n';
}

int main(){
  // fast
  freopen("knights.in","r",stdin);
  int t;
  scanf("%d",&t);
  // cin>>t;
  while(t--)solve(); 
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/