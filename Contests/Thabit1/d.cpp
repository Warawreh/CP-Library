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
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m),c(n),f(n + 1);
	vector<vector<int>> at(n + 1);
	for(int i=0;i<n;i++){
		cin>>a[i];
		at[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
		f[b[i]] = 1;
	}
	ll tot = 0;
	for(int i=0;i<n;i++){
		if(f[a[i]] == 0)tot += min(0 , c[i]);
	}
	
	vector<pair<ll,ll>> cur,nxt;
	cur.push_back({-1,0});
	for(int i=0;i<m;i++){
		ll sum = 0;
		nxt.clear();
		nxt.push_back({-1,1e13});
		ll best = 1e13;	
		int att = 0;
		for(int j : at[b[i]])if(c[j] < 0)sum += c[j];
		for(int j : at[b[i]]){
			while(att < cur.size() && cur[att].first < j){
				best = min(best , cur[att].second);
				att++;
			}
			if(c[j] < 0)sum -= c[j];
			nxt.push_back({j,best + sum});
			if(c[j] < 0)sum += c[j];
		}
		cur = nxt;
	}
	ll ans = 0;
	for(int i=0;i<cur.size();i++)ans = min(ans , cur[i].second);
	cout << ans + tot << '\n';
}