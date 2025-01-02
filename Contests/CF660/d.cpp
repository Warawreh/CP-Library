#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	ll n;
	cin>>n;

	ll ans = 0;
	vector<vector<ll>> g(n),rev(n);
	vector<ll> in(n,0),out(n,0);
	vector<ll> a(n),b(n);
	vector<bool> vis(n);


	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	for(ll i=0;i<n;i++){
		cin>>b[i];
		b[i]--;
		if(b[i] != -2){
			in[b[i]]++;
			g[i].push_back(b[i]);
		}
	}

	queue<ll> q;
	for(ll i=0;i<n;i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	vector<ll> seq;
	while(q.size()){
		ll u = q.front();
		q.pop();
		if(a[u] < 0){
			for(ll v : g[u]){
				in[v]--;
				if(in[v] == 0)q.push(v);
			}
			continue;
		}
		vis[u] = 1;
		ans += a[u];
		seq.push_back(u);
		for(ll v : g[u]){
			in[v]--;
			a[v] += a[u];
			if(in[v] == 0)q.push(v);
		}
	}

	function<void(int)> go = [&](int u){
		if(vis[u])return;
		vis[u] = 1;
		for(int v : g[u])go(v);
		ans += a[u];
		seq.push_back(u);
		return;
	};

	for(ll i=0;i<n;i++){
		if(!vis[i]){
			go(i);
		}
	}

	cout << ans << '\n';
	// assert(seq.size() == n);
	for(ll i : seq){
		cout << i + 1 << ' ';
	}
	cout << '\n';
}