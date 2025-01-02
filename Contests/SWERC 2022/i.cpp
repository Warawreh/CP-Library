#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll oo = 1e18;

int main(){
	fast
	ll n,m;
	cin>>n>>m;
	vector<ll> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i];
		if(i)p[i] += p[i-1];
	}
	vector<ll> s(m);
	for(int i=0;i<m;i++)cin>>s[i];
	s.push_back(-oo);
	s.push_back(oo);
	sort(all(s));
	int l = 0;
	ll ans = 0;
	for(int i=0;i<n;i++){
		while(s[l] <= i * 100)l++;
		ll lb = s[l-1],rb = s[l];
		if(lb == i*100)continue;
		ll lo = i,hi = n-1;
		assert(lb < i*100); 
		ll dist = i*100 - lb - 1;
		ll at = i*100 + dist;
		at = min(at , rb-1);
		ll to = (rb + at)/2;
		// cerr << to << '\n';
		to = min(to , (n-1) * 100LL);
		ans = max(ans , p[to/100]  - (i ? p[i-1] : 0LL));
		// while(lo <= hi){
		// 	ll md = (lo + hi)/2;
		// 	if(md*100 <= to){	
		// 		lo = md+1;
		// 		ans = max(ans , p[md] - (i ? p[i-1] : 0LL));
		// 	}else hi = md-1;
		// }
	}

	cout << ans << '\n';

}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/