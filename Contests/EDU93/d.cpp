#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 202;
ll dp[nax][nax][nax];
int r,g,y;
vector<ll> a,b,c;

ll calc(int i,int j,int l){
	if((i == r) + (j == g) + (l == y) >= 2)return 0;
	ll &ret = dp[i][j][l];
	if(ret != -1)return ret;
	ret = 0;
	if(i != r && j != g)ret = max(ret , a[i] * b[j] + calc(i+1,j+1,l));
	if(i != r && l != y)ret = max(ret , a[i] * c[l] + calc(i+1,j,l+1));
	if(l != y && j != g)ret = max(ret , c[l] * b[j] + calc(i,j+1,l+1));
	return ret;
}

int main(){
	fast
	cin>>r>>g>>y;
	a.resize(r);b.resize(g);c.resize(y);
	for(auto &i : a)cin>>i;
	for(auto &i : b)cin>>i;
	for(auto &i : c)cin>>i;
	sort(all(a));sort(all(b));sort(all(c));
	reverse(all(a));reverse(all(b));reverse(all(c));
	memset(dp,-1,sizeof(dp));
	cout << calc(0,0,0) << '\n';
}