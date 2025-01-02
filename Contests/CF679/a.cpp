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
	ll n,m=6;
	vector<ll> a(m);
	for(ll i=0;i<m;i++)cin>>a[i];
	cin>>n;
	vector<ll> b(n);
	vector<pair<ll,ll>> s;
	for(ll i=0;i<n;i++){
		cin>>b[i];
		for(ll j=0;j<m;j++){
			s.push_back({b[i] - a[j] , i});
		}
	}
	sort(all(s));
	ll lo=0,hi=2e9,ans=2e9;
	vector<ll> vis(n,0);
	while(lo <= hi){
		ll md = (lo + hi)/2;
		ll l=0,cur=0,mx=0;
		for(ll i=0;i<s.size();i++){
			if(vis[s[i].second] == 0)cur++;
			vis[s[i].second]++;
			while(l < i && s[i].first - s[l].first > md){
				if(vis[s[l].second] == 1)cur--;
				vis[s[l].second]--;
				l++;
			}
			mx = max(mx , cur);
		}
		while(l < s.size()){
			vis[s[l].second] = 0;
			l++;
		}

		if(mx == n){
			hi = md-1;
			ans = md;
		}else lo = md+1;
	}
	cout << ans << '\n';
}