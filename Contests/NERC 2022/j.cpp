#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<ll>> s,c;
int n;

void build(vector<vector<ll>> &c){
	s = vector<vector<ll>>(n,vector<ll>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s[i][j] = c[i][j] + (i ? s[i-1][j] : 0LL) + (j ? s[i][j-1] : 0LL) - (i && j ? s[i-1][j-1] : 0LL);
		}	
	}
}

ll getSum(ll r1,ll r2,ll c1,ll c2){
	if(r1 > r2 || c1 > c2 || r1 >= n || c1 >= n)return 0;
	return s[r2][c2] - (r1 ? s[r1 - 1][c2] : 0LL) - (c1 ? s[r2][c1-1] : 0LL) + (r1 && c1 ? s[r1-1][c1-1] : 0LL);
}

const int nax = 202;
ll dp[nax][nax];

ll calc(int l,int r){
	if(l > r)return 0;
	// cerr << l << ' ' << r << '\n';
	ll &ret = dp[l][r];
	if(ret != -1)return ret;
	ret = 1e18;

	ll val = getSum(l,r,r+1,n-1) + getSum(0,l-1,l,r);
	if(l == r)ret = val;

	for(int md=l;md<=r;md++){
		ret = min(ret , calc(l,md-1) + calc(md+1,r) + val);
	}
	// cerr << l << ' ' << r << ' ' << val << ' ' << ret << '\n';
	return ret;

}

vector<int> par;
void build(int l,int r,int p){
	if(l == r){
		par[l] = p+1;
		return;
	}
	ll val = getSum(l,r,r+1,n-1) + getSum(0,l-1,l,r);
	for(int md=l;md<=r;md++){
		if(calc(l,md-1) + calc(md+1,r) + val == calc(l,r)){
			par[md] = p+1;
			build(l,md-1,md);
			build(md+1,r,md);
			return;
		}
	}
	assert(-1);
}

int main(){
	fast
	cin>>n;
	c = vector<vector<ll>>(n,vector<ll>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>c[i][j];

	build(c);
	par.resize(n,-1);
	memset(dp,-1,sizeof(dp));
	// cout << calc(0,n-1) << '\n';
	build(0,n-1,-1);
	for(int i=0;i<n;i++){
		cout << par[i] << ' ';
	}
	cout << '\n';

}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/