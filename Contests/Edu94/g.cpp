#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int COM_LEN = 1e6 + 10;
ll Pow(ll a,ll b){
	if(!b)return 1;
	ll res = Pow(a,b/2);
	res = (res * res) % mod;
	if(b%2)res = (res * a)%mod;
	return res;
}
ll fac[COM_LEN],inv[COM_LEN];
void init_COM(){
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i=2;i<COM_LEN;i++){
		fac[i] = (fac[i-1] * i) % mod;
		inv[i] = Pow(fac[i] , mod-2);
	}
}
inline ll nCk(ll n, ll k){
	return ((fac[n] * inv[k])%mod * inv[n-k])%mod;
}
inline ll nPk(ll n,ll k){
	return (fac[n]*inv[n-k])%mod;
}

/*
	Put in the begin of the code
		init_COM() 
	COM_LEN = The size of the numbers
*/

int main(){
	fast
	init_COM();
	int n,m;
	cin>>n>>m;
	vector<vector<int>> e(n+2);
	vector<int> hn(n+1),hm(m+1);
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		e[l].push_back(i);
		e[r+1].push_back(-i);
	}

	vector<pair<int,int>> edges(m);
	for(int i=0;i<m;i++)cin>>edges[i].first>>edges[i].second;
	ll ans = 0;
	int cur = 0;
	for(int t=1;t<=n;t++){
		for(int id : e[t]){
			if(id < 0){//rem
				id = -id;
				cur--;
				hn[id] = 0;
			}else if(id > 0){//add
				cur++;
				hn[id] = 1;
			}
		}
		int edge = 0;
		for(int i=0;i<m;i++){
			if(hn[edges[i].first] && hn[edges[i].second])hm[i] = 1;
			else hm[i] = 0;
			edge += hm[i];
		}

		
		if(cur >= t){
			ans = (ans + nCk(cur , t))%mod;
		}
	}
}