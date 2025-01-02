#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<ll,char>>> g;
ll n;

ll nC2(ll n){
	if(n < 2)return 0;
	return n * (n-1) / 2;
}

ll nC3(ll n){
	if(n < 3)return 0;
	return n * (n-1) * (n-2) / 6;
}

map<pair<ll,ll>,int> hv;
ll ans;

const int mod = 1e9 + 7;

int p[2] = {31,37};

void dfs(int u,pair<ll,ll> val){
	hv[val]++;
	for(auto &[v , w] : g[u]){
		pair<ll,ll> nval = {((val.first * p[0]) + (w - 'a' + 1))%mod , ((val.second * p[1]) + (w - 'a' + 1))%mod};
		dfs(v,nval);
	}
}

void solve(){
	cin>>n;

	ans = 0;
	hv.clear();
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		g.clear();
		g.resize(m);
		for(int j=1;j<m;j++){
			int p;
			char c;
			cin>>p>>c;
			p--;
			g[p].push_back({j , c});
		}
		dfs(0 , {0,0});
	}

	for(auto cur : hv){
		ll cnt = cur.second;
		ans += nC2(n - cnt) * cnt;
		ans += nC2(cnt) * (n - cnt);
		ans += nC3(cnt);
		// cerr << cur.first << ' ' << cur.second << ' ' << nC2(n - cnt) << '\n';
		// if(cnt >= 2){
		// 	ans -= nC2(cnt);
		// }
		// if(cnt >= 3){
		// 	ans -= nC3(cnt);
		// }
	}

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cerr << T << ',';
		cout << "Case #" << T << ": ";
		solve();
	}
}