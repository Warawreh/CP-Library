#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e6 + 10;
const int mod = 1e9+7;

int p[2] = {31,37};
ll inv[2][nax],POW[2][nax];

ll Pow(ll a,ll b){
	if(!b)return 1;
	ll ret = Pow(a,b/2);
	if(b%2)return ((ret*ret)%mod*a)%mod;
	return (ret*ret)%mod;
}

void init(){
	POW[0][0] = POW[1][0] = 1;
	inv[0][0] = inv[1][0] = Pow(POW[0][0],mod-2);
	for(int i=1;i<nax;i++){
		for(int x=0;x<2;x++){
			POW[x][i] = (POW[x][i-1] * p[x]) % mod;
			if(i == 1)inv[x][i] = Pow(POW[x][i],mod-2);
			else inv[x][i] = (inv[x][i-1] * 1LL * inv[x][1])%mod;
		}
	}

}

struct HASH{
	vector<ll> sum[2];
	void init(int n){
		sum[0].resize(n + 1);
		sum[1].resize(n + 1);
	}

	void build(string s){
		for(int i=0;i<s.size();i++){
			for(int x=0;x<2;x++){
				sum[x][i+1] = ((s[i] - 'a' + 1) * POW[x][i])%mod;
				sum[x][i+1] = (sum[x][i+1] + sum[x][i]) %mod;
			}
		}
	}
	pair<ll,ll> check(int l,int r){
		ll h1 = ((sum[0][r+1] - sum[0][l] + mod)%mod * inv[0][l])%mod;
		ll h3 = ((sum[1][r+1] - sum[1][l] + mod)%mod * inv[1][l])%mod;
		return {h1,h3};
	}
	bool check(int l1,int r1,int l2,int r2){
		ll h1 = ((sum[0][r1+1] - sum[0][l1] + mod)%mod * inv[0][l1])%mod;
		ll h2 = ((sum[0][r2+1] - sum[0][l2] + mod)%mod * inv[0][l2])%mod;
		ll h3 = ((sum[1][r1+1] - sum[1][l1] + mod)%mod * inv[1][l1])%mod;
		ll h4 = ((sum[1][r2+1] - sum[1][l2] + mod)%mod * inv[1][l2])%mod;
	  	return h1==h2 && h3==h4;
	}
};

ll A(ll &a,ll b){
	a += b;
	if(a >= mod)a -= mod;
	if(a < 0)a += mod;
	return a;
}

struct BIT{
	vector<ll> tree;
	int n;
	void init(int N){
		n = N;
		tree = vector<ll> (n+1,0);
	}
	void update(int x,ll val){
		val %= mod;
		while(x <= n){
			A(tree[x] , val);
			x += x&(-x);
		}
	}
	ll get(int x){
		ll res = 0;
		while(x){
			A(res , tree[x]);
			x -= x&(-x);
		}
		return res;
	}
	ll get(int l,int r){
		if(l > r)return 0;
		return get(r) - get(l-1);
	}
};

vector<HASH> h;
BIT t[2];


int main(){
	fast
	init();	
	int n;
	cin>>n;
	h.resize(n);
	vector<pair<int,int>> g;
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
		h[i].init(s[i].size() + 1);
		for(int j=0;j<s[i].size();j++){
			g.push_back({i,j});
		}
		g.push_back({i,s[i].size()});
		h[i].build(s[i]);
	}
	// g.clear();
	// g.push_back({0,3});
	// g.push_back({1,0});

	auto get = [&](pair<int,int> a,int md){
		pair<ll,ll> val;
		if(a.second <= md){
			if(a.second)
				val = h[a.first].check(0,a.second - 1);
			else
				val = {0,0};
			pair<ll,ll> tmp = h[a.first].check(a.second + 1 , md + 1);
			val.first = (val.first + (tmp.first * POW[0][a.second])%mod)%mod;
			val.second = (val.second + (tmp.second * POW[1][a.second])%mod)%mod;
		}else{
			val = h[a.first].check(0,md);
		}
		// cerr << a.first << ' ' << a.second << ' ' << val.first << '\n';
		return val;
	};

	sort(all(g),[&](pair<int,int> a,pair<int,int> b){
		int lo = 0,hi = min(s[a.first].size() - (a.second != s[a.first].size()) , s[b.first].size()  - (b.second != s[b.first].size())) - 1,ans = -1;
		while(lo <= hi){
			int md = (lo + hi)/2;
			//find value a and b
			pair<ll,ll> vala = get(a,md),valb = get(b,md);
			if(vala == valb){//equel
				lo = md + 1;
				ans = md;
			}else{
				hi = md-1;
			}
		}
		ans++;
		if(ans + (ans >= a.second) >= s[a.first].size() && ans + (ans >= b.second) >= s[b.first].size())return a.first < b.first;
		if(ans + (ans >= a.second) >= s[a.first].size())return true;
		if(ans + (ans >= b.second) >= s[b.first].size())return false;
		char x = s[a.first][ans + (ans >= a.second)];
		char y = s[b.first][ans + (ans >= b.second)];
		// cerr << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << ' '<< ans << '\n';
		// cerr << x << ' ' << y << '\n';
		return x < y;
	});
	vector<vector<int>> at(n);
	for(int i=0;i<g.size();i++){
		at[g[i].first].push_back(i + 1);
		// cerr << g[i].first << ' ' << g[i].second << '\n';
	}
	t[0].init(g.size());
	t[1].init(g.size());
	for(int i : at[0]){
		t[0].update(i , 1);
	}
	for(int i=1;i<n;i++){
		ll ans = 0;
		int bit = i%2;
		for(int j : at[i]){
			t[bit].update(j , t[!bit].get(j));
		}
		for(int j : at[i-1]){
			t[!bit].update(j , -t[!bit].get(j));
		}
	}
	cout << t[!(n%2)].get(g.size()) << '\n';

}

