#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int nax = 2020;

int dp[nax][nax][2];
int vis[nax][nax][2];
int n,k,m,to;

int calc(int i,int mo,bool t){
	if(i == to)t = 1;
	if(mo == m)return (t && i == 0);
	int &ret = dp[i][mo][t];
	if(vis[i][mo][t] == to)return ret;
	vis[i][mo][t] = to;
	ret = 0;
	if(i == to)ret =  calc(i - 1,mo+1,t);
	else if(i == 0)ret = calc(i+1,mo+1,t);
	else ret = (calc(i+1,mo+1,t) + calc(i - 1,mo+1,t))%mod;
	if(t && i == 0)ret = (ret + 1)%mod;
	return ret;
}

ll T[nax][nax];


int main(){
	fast
	cin>>n>>k>>m;

	//T(n,0) = n+1, T(n,k) = 2*T(n-1,k) - T(n-1,k-1), T(n,k) = 0
	T[0][0] = 1;
	for(int i=1;i<=m;i++){
		T[i][0] = i+1;
		// cerr << T[i][0] << ' ';
		for(int j=1;j<=i;j++){
			T[i][j] = ((2 * T[i-1][j])%mod + T[i-1][j-1])%mod;
			// cerr << T[i][j] << ' ';
		}
		// cerr << '\n';
	}

	ll ans2 = 0;
	for(int i=1;i <= min(k,m/2);i++){
		to = i;
		ans2 = (ans2 + calc(0,0,0))%mod;
		cerr << calc(0,0,0) << ' ';
	}
	cerr << '\n';

	ll ans = 0;
	m/=2;

	for(int j=0;j<m;j++){
		ll val = T[m-1][j];
		ans = (ans + val)%mod;
		// cerr << val << ' ';
	}
	
	cerr << ans << ' ' << ans2 << '\n';
	ans *=2;
	ans%=mod;
	ans*=n;
	ans%=mod;
	cout << ans << '\n';
}