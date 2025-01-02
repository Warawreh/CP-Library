#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> p,q;
vector<pair<ll,bool>> x,y;
int n,m,k,s;

bool check(ll md){
	ll g=-1,b=-1,w=0,y=0;
	for(int i=0;i<x.size();i++){
		ll at = x[i].first;
		bool t = x[i].second;
		if(t == 1){//good
			if(b == -1){
				g = at + md;
				w = y = 0;
			}else{
				ll dist = at - b;
				if(dist > md)return false;
				g = b + md - dist;
				w = dist;
				y = b;
				b = -1;
			}
		}else{//bad
			if(g != -1){
				if(g < at){
					ll p = -(g - md - 2 * y);
					ll dist = at - p;
					// if(i == 2 && md == 12){
						// cerr << dist << ' ' << p << ' ' << w << '\n';
					// }
					if(dist * 2 + w > md){
						g = -1;
						b = at;
					}
				}
			}else{
				if(b == -1)b = at;
			}
		}
		// if(md == 12)cerr << i << ' ' << g << ' ' << w << ' ' << b << '\n';
	}
	if(b != -1)return false;
	return true;
}

void solve(){
	cin>>n>>m>>k>>s;
	p.clear();q.clear();x.clear();
	p.resize(k);q.resize(k);
	for(ll &i : p)cin>>i;
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=k;i<n;i++){
			ll val = (a * p[i-2])%d;
			val = (val + b * p[i-1])%d;
			val = (val + c)%d;
			p.push_back(val + 1);
		}
	}
	for(ll &i : q)cin>>i;
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=k;i<m;i++){
			ll val = (a * q[i-2])%d;
			val = (val + b * q[i-1])%d;
			val = (val + c)%d;
			q.push_back(val + 1);
		}
	}

	for(ll i : p)x.push_back({i,1});
	for(ll i : q)x.push_back({i,0});
	sort(all(x));
	y = x;
	reverse(all(y));
	ll lo = 0,hi = 1e18,ans = 1e18;

	while(lo <= hi){
		ll md = (lo + hi)/2;
		if(check(md)){
			hi = md-1;
			ans = md;
		}else lo = md + 1;
	}

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}