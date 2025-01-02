#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,k;
string s;
vector<vector<ll>> g,r;
vector<ll> id,sz,sub;
ll T;
ll mx1,mx2,cnt1,cnt2;
ll ans;

void dfs(ll u){
	id[u] = T;
	sz[T] += s[u - 1] == '*';
	for(ll v : g[u]){
		if(s[v - 1] == '#')continue;
		dfs(v);
	}
}

int go(int u){
	ll good= s[u-1] == '*';
	sub[u] = 1;
	for(ll v : g[u]){
		ll res = go(v);
		sub[u] += sub[v];
		if(s[u-1] == '#' || s[v-1] == '#'){
			ans += sub[v] * 1LL * (n - sub[v]);
		}else{
			ans += res * 1LL * (mx1 - res);
		}
		good += res;
	}
	return good;
}

pair<ll,ll> go2(ll u){
	pair<ll,ll> good = {sz[u] == mx1 , sz[u] == mx2};
	for(ll v : r[u]){
		pair<ll,ll> res = go2(v);

		pair<ll,ll> up = {cnt1 - res.first , cnt2 - res.second};
		// cerr << u << ' ' << v << ' ' << up.first << ' ' << up.second << '\n';
		// cerr << res.first << ' ' << res.second << '\n';
		ans += mx1 * mx2 * (up.first * res.second + up.second * res.first);

		good.first += res.first;
		good.second += res.second;
	}
	return good;
}

void solve(){
	cin>>n>>k>>s;
	{
		ans = 0;
		T = 0;
		cnt1 = cnt2 = mx1 = mx2 = 0;
		g.clear();
		id = sub = vector<ll> (n+1,0);
		sz.clear();
		g.resize(n+1);
	}
	vector<ll> p(k);
	for(ll i=0;i<k;i++){
		cin>>p[i];
	}
	{
		ll a,b,c,d;
		cin>>a>>b>>c;
		for(ll i=k;i<n - 1;i++){
			d = (i-1) + 2;
			ll val = (a * p[i-2])%d;
			val = (val + b * p[i-1])%d;
			val = (val + c)%d;
			p.push_back(val + 1);
		}
	}
	
	for(ll i=0;i<n-1;i++){
		ll u = i+2;
		ll par = p[i];
		g[par].push_back(u);
		// cerr << par << ' ' << u << '\n';
	}
	sz.push_back(0);
	for(ll u=1;u<=n;u++){
		if(u == 1 && s[u-1] == '*'){
			T++;
			sz.push_back(0);
			dfs(u);
		}else{
			if(s[u-1] == '#'){
				sz.push_back(0);
				T++;
				id[u] = T;
				for(ll v : g[u]){
					if(s[v-1] == '#')continue;
					T++;
					sz.push_back(0);
					dfs(v);
				}
			}
		}
	}
	{
		vector<ll> tmp = sz;
		sort(all(tmp));
		if(tmp.size()){
			mx1 = tmp.back();
			tmp.pop_back();
		}
		if(tmp.size())mx2 = tmp.back();
		// cerr << mx1 << ' ' << mx2 << '\n';
		for(ll i : sz){
			if(i == mx1)cnt1++;
			if(i == mx2)cnt2++;
		}
		// cerr << mx1 << ' ' << mx2 << '\n';
		// cerr << cnt1 << ' ' << cnt2 << '\n';
		if(mx2 == 0)go(1);
		else{//make new tree then dfs it
			r.clear();
			r.resize(T+1);
			for(ll u=1;u<=n;u++){
				for(ll v : g[u]){
					if(id[u] == id[v])continue;
					r[id[u]].push_back(id[v]);
				}
			}
			go2(id[1]);
			if(mx1 == mx2){
				assert(ans %2 == 0);
				ans/=2;
			}
		}
		cout << (mx1 + mx2) * (mx1 + mx2 - 1)/2 << ' ' << ans << '\n';
	}
}

int main(){
	fast
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}	
}