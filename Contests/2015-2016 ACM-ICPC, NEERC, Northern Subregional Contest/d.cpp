#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()

map<ll,bool> good,used;
map<ll,ll> w;
map<ll,vector<ll>> dp[66][66];
map<ll,bool> vis[66][66];

vector<ll> calc(ll n,int a,int b){
	if(n < 0)return {-1};
	if(n==0)return {};
	// if(n == 1)return {-1};
	// if(good[n])return {n};
	if(vis[a][b][n])return dp[a][b][n];
	// cerr << a << ' ' << b << ' ' << n << '\n';
	vis[a][b][n] = 1;
	vector<ll> ret = {-1};
	ll v = 1;
	int cnt1=0;
	while(n%2==0){
		v*=2;
		n/=2;
		cnt1++;
	}
	// cerr << a << ' ' << b << ' ' << n << ' ' << cnt1 << '\n';
	a-=cnt1;
	if(cnt1 && cnt1 > a)return dp[a][b][n*v] = {-1};
	cnt1=0;
	while(n%3==0){
		v*=3;
		n/=3;
		cnt1++;
	}
	if(cnt1 && cnt1 > b)return dp[a][b][n*v] = {-1};
	b-=cnt1;
	if(n == 1)return dp[a][b][n*v] = {v};
	ll w2 = 1;
	for(ll k = 1;k<a;k++){
		w2*=2;
		if(w2 <= n){
			vector<ll> cur = calc(n - w2,k,b);
			// cerr << n << ' ' << w2 << ' ' << cur[0] << '\n';
			if(cur.size() && cur[0] == -1)continue;
			ret = cur;
			ret.push_back(w2);
			break;
		}
	}
	ll w = 1;
	for(ll k =1;k<b;k++){
		w*=3;
		if(w <= n){
			vector<ll> cur = calc(n - w,a,k);
			// cerr << n << ' ' << w << ' ' << cur[0] << '\n';
			if(cur.size() && cur[0] == -1)continue;
			ret = cur;
			ret.push_back(w);
			break;
		}
	}
	// cerr << a << ' ' << b << ' ' << n << '\n';
	if(ret[0] == -1){
		dp[a][b][n*v] = ret;
		return ret;	
	}
	// cerr << n << ' ' << a << ' ' << b << ' ' << ret[0] << '\n';
	for(ll &a : ret)a *= v;
	dp[a][b][n*v] = ret;
	return ret;
}

int main(){
	// freopen("distribution.in" , "r" , stdin);
	// freopen("distribution.out" , "w" , stdout);
	vector<ll> num;
	vector<pair<ll,ll>> num2;
	ll cur = 1;
	for(int i=0;i<64;i++){
		ll tmp = cur;
		for(int j=0;j<64;j++){
			num.push_back(tmp);
			good[tmp] = 1;
			if(tmp > (1e18+2)/3)break;
			tmp *= 3;
		}
		if(cur > (1e18/2))break;
		cur *= 2;
	}
	sort(all(num));
	for(ll x : num){
		for(ll y : num){
			if(y % x == 0 || y % x == 0)continue;
			w[x + y] = x;
		}
	}
	int t;
	cin>> t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> ans;
		ans = calc(n,62,38);
		cout << ans.size() << '\n';
		for(ll i : ans)
			cout << i << ' ';
		cout << '\n';
	}
}