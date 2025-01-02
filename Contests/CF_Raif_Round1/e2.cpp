#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll S(ll a){return a*a;}

ll cst(ll a,ll d){
	ll s = a / d;
	ll md = a % d;
	ll v = a - s * (d - md);
	if(md)v /= md;
	else v = 0;
	ll res = (d - md) * S(s) + S(v) * md;;
	return res;
}

int main(){
	fast
	ll n,k;
	cin>>n>>k;
	vector<ll> d(n);
	vector<ll> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	ll res = 0;
	multiset<vector<ll>> x;
	for(int i=0;i<n;i++){
		d[i] = 1;
		x.insert({S(a[i]) - cst(a[i],d[i] + 1),a[i],i});
	}
	ll have = n;
	while(have < k){
		ll v = (*x.rbegin())[1];	
		ll id = (*x.rbegin())[2];
		// cerr << (*x.rbegin())[0] << ' ' << v << ' ' << id << '\n';
		if(v==1)break;
		have++;
		x.erase(x.lower_bound(*x.rbegin()));
		d[id]++;
		x.insert({cst(a[id] , d[id]) - cst(a[id] , d[id] + 1),a[id],id});
	}
	for(int i=0;i<n;i++){
		res += cst(a[i] , d[i]);
	}
	cout << res << '\n';
}