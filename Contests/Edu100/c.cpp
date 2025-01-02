#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	ll n;
	cin>>n;
	ll at = 0;
	ll t = 0;
	ll dir = 0,cur = -1;
	ll ans = 0,dist = 0;
	vector<pair<ll,ll>> e(n);
	for(ll i=0;i<n;i++){
		ll time,x;
		cin>>time>>x;
		e[i] = {time,x};
	}
	e.push_back({1e18,1});
	for(int i=0;i<n;i++){
		ll time = e[i].first;
		ll to = e[i].second;
		at += dir * (time - t);
		if(dir == 1)at = min(at , dist);
		else if(dir == -1)at = max(at, dist);
		t = time;
		if(at == dist){
			dir = 0;
		}

		if(dir == 0){
			dist = to;
			if(to == at){
				ans++;
			}else if(to < at){
				dir = -1;
				if(at - (e[i+1].first - time) <= to)ans++;
			}else{
				dir = 1;
				if(at + (e[i+1].first - time) >= to)ans++;
			}
			// cerr << i << '\n'
		}else{
			if(dir == 1){
				if(to >= at && at + (e[i+1].first - time) >= to && to <= dist)ans++;
			}else if(dir == -1){
				if(to <= at && at - (e[i+1].first - time) <= to && to >= dist)ans++;
			}
		}
		// cerr << i << ' ' << dir << ' ' << dist << ' ' << at << ' ' << ans << '\n';
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}