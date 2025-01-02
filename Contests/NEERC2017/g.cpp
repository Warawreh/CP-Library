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
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> g(n,vector<ll>(m));
	vector<ll> r(n),c(m);
	ll o = 0,e = 0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			ll rr,cc;	
			cin>>rr>>cc;
			g[i][j] += rr;
			g[i][(j+1)%m] -= rr;
			r[i] += cc;
			c[j] += rr;
			g[i][j] += cc;
			g[(i+1)%n][j] -= cc;
		}
	}
	for(ll i=0;i<n;i++){
		if(r[i]){
			cout << "No\n";
			return 0;
		}
	}
	for(ll i=0;i<m;i++){
		if(c[i]){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}