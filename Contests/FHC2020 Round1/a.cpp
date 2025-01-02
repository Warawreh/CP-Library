#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

struct node{
	ll mx1,mx2;
	ll p,x;
	node(){
		mx1 = mx2 = p = x = 0;
	}
};

ll A(ll &x,ll a){
	x += a;
	if(x < 0)x+=mod;
	if(x >= mod)x-=mod;
	return x;
}

void solve(){
	ll n,k,w;
	cin>>n>>k>>w;
	vector<ll> l(k),h(k);
	for(ll &i : l)cin>>i;
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=k;i<n;i++){
			ll val = (a * l[i-2])%d;
			val = (val + b * l[i-1])%d;
			val = (val + c)%d;
			l.push_back(val + 1);
		}
	}
	for(ll &i : h)cin>>i;
	// cerr << h[0] << '\n';
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=k;i<n;i++){
			ll val = (a * h[i-2])%d;
			val = (val + b * h[i-1])%d;
			val = (val + c)%d;
			h.push_back(val + 1);
		}
	}
	assert(is_sorted(all(l)));
	ll ans = 1;
	ll p = 0;
	vector<node> q;
	int at = 0;
	for(int i=0;i<n;i++){
		p = (p + 2*w + 2*h[i])%mod;
		while(at < q.size() && q[at].x < l[i])at++;
		p = (p - (max(0,((int)q.size() - at - 1)) * 2LL)%mod + mod)%mod;
		for(int j=at;j<q.size();j++){
			if(j == at){
				A(p , -(q[j].mx1 - q[j].mx2));
				A(p , -h[i]);
				// cerr << q[j].mx1 << ' ' << q[j].mx2 << '\n';
				if(h[i] > q[j].mx1){
					q[j].mx2 = q[j].mx1;
					q[j].mx1 = h[i];
				}else if(h[i] > q[j].mx2)q[j].mx2 = h[i];
				q[j].mx2 = max(q[j].mx2 , q[j].p);
				q[j].mx1 = max(q[j].mx1 , q[j].p);
				A(p , (q[j].mx1 - q[j].mx2));
			}else{
				A(p , -(q[j].mx1 - q[j].mx2));
				q[j].p = max(q[j].p , h[i]);
				q[j].mx2 = max(q[j].mx2 , q[j].p);
				q[j].mx1 = max(q[j].mx1 , q[j].p);
				A(p , (q[j].mx1 - q[j].mx2));
			}
		}

		for(int j=at;j<=at+w;j++){
			if(j >= q.size()){
				node tmp;
				tmp.x = l[i] + j - at;
				if(j == at+w){
					tmp.mx1 = h[i];
				}else{
					tmp.p = h[i];
				}
				q.push_back(tmp);
			}
		}

		assert(p >= 0);
		ans = (ans * p)%mod;
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