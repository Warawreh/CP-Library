#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int SZ = 2e4 + 2;
const int mod = 1e9+7;
int p[2] = {101,37};
ll inv[2][SZ],POW[2][SZ],sum[2][SZ];
ll Pow(ll a,ll b){
	if(!b)return 1;
	ll ret = Pow(a,b/2);
	if(b%2)return ((ret*ret)%mod*a)%mod;
	return (ret*ret)%mod;
}	
void init(){
	POW[0][0] = POW[1][0] = 1;
	inv[0][0] = inv[1][0] = Pow(POW[0][0],mod-2);
	for(int i=1;i<SZ;i++){
		for(int x=0;x<2;x++){
			POW[x][i] = (POW[x][i-1] * p[x]) % mod;
			inv[x][i] = Pow(POW[x][i],mod-2);
		}
	}

}
void build(string s){
	for(int i=0;i<s.size();i++){
		for(int x=0;x<2;x++){
			sum[x][i+1] = ((s[i] - 'a' + 1) * POW[x][i])%mod;
			sum[x][i+1] = (sum[x][i+1] + sum[x][i]) %mod;
		}
	}
}

void solve(){
	int n;
	cin>>n;
	map<pair<int,int>,int> hv,hv2;
	string v = "meta";
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		build(s);
		pair<ll,ll> val = {sum[0][s.size()] , sum[1][s.size()]};
		hv2[val]++;
		for(int j=0;j<s.size();j++){
			val.first -= ((s[j] - 'a' + 1) * POW[0][j])%mod;
			if(val.first < 0)val.first += mod;

			val.second -= ((s[j] - 'a' + 1) * POW[1][j])%mod;
			if(val.second < 0)val.second += mod;

			for(int to=0;to<4;to++){
				if(s[j] == v[to])continue;

				val.first += ((v[to] - 'a' + 1) * POW[0][j])%mod;
				if(val.first >= mod)val.first -= mod;

				val.second += ((v[to] - 'a' + 1) * POW[1][j])%mod;
				if(val.second >= mod)val.second -= mod;

				hv[val]++;
				

				val.first -= ((v[to] - 'a' + 1) * POW[0][j])%mod;
				if(val.first < 0)val.first += mod;

				val.second -= ((v[to] - 'a' + 1) * POW[1][j])%mod;
				if(val.second < 0)val.second += mod;
			}
			val.first += ((s[j] - 'a' + 1) * POW[0][j])%mod;
			val.first %= mod;

			val.second += ((s[j] - 'a' + 1) * POW[1][j])%mod;
			val.second %= mod;
		}

	}
	int m;
	cin>>m;
	ll ans = 0;
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		build(s);
		pair<ll,ll> val = {sum[0][s.size()] , sum[1][s.size()]};
		pair<ll,ll> tmp = val;
		ans -= (hv[val] * 2);

		for(int j=0;j<s.size();j++){
			val.first -= ((s[j] - 'a' + 1) * POW[0][j])%mod;
			if(val.first < 0)val.first += mod;

			val.second -= ((s[j] - 'a' + 1) * POW[1][j])%mod;
			if(val.second < 0)val.second += mod;
			
			for(int to=0;to<4;to++){
				if(s[j] == v[to])continue;
				val.first += ((v[to] - 'a' + 1) * POW[0][j])%mod;
				if(val.first >= mod)val.first -= mod;

				val.second += ((v[to] - 'a' + 1) * POW[1][j])%mod;
				if(val.second >= mod)val.second -= mod;


				ans += hv[val];
				ans -= hv2[tmp];

				val.first -= ((v[to] - 'a' + 1) * POW[0][j])%mod;
				if(val.first < 0)val.first += mod;

				val.second -= ((v[to] - 'a' + 1) * POW[1][j])%mod;
				if(val.second < 0)val.second += mod;
			}
			val.first += ((s[j] - 'a' + 1) * POW[0][j])%mod;
			if(val.first >= mod)val.first -= mod;

			val.second += ((s[j] - 'a' + 1) * POW[1][j])%mod;
			if(val.second >= mod)val.second -= mod;
		}

	}
	cout << ans/2 << '\n';

}

int main(){
	fast
	init();	
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cerr << T << ',';
		cout << "Case #" << T << ": ";
		solve();
	}
}