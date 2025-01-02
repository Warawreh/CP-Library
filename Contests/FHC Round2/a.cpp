#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k;

void complete(vector<ll> &x){
	ll a,b,c,d;
	x.resize(n);
	for(int i=0;i<k;i++){
		if(i < k)cin>>x[i];
	}
	cin>>a>>b>>c>>d;
	for(int i=k;i<n;i++){
		x[i] = ((a * x[i-2])%d + (b * x[i-1])%d + c)%d;
	}
}

void solve(){
	cin>>n>>k;
	vector<ll> s,x,y;
	complete(s);
	complete(x);
	complete(y);
	{
		ll sum1=0,sum2=0,sum3=0;
		for(int i=0;i<n;i++){
			sum1 += s[i];
			sum2 += x[i];
			y[i] += x[i];
			sum3 += y[i];
		}
		if(sum2 <= sum1 && sum3 >= sum1){

		}else{
			cout << -1 << '\n';
			return;
		}
	}

	vector<vector<pair<ll,ll>>> hv(2);
	for(int i=0;i<n;i++){
		if(s[i] < x[i])hv[0].push_back({x[i] - s[i] , i});
		if(s[i] > y[i])hv[1].push_back({s[i] - y[i] , i});
	}

	ll ans = 0;
	while(hv[0].size() && hv[1].size()){
		ll k = min(hv[0].back().first , hv[1].back().first);
		hv[0].back().first -= k;
		hv[1].back().first -= k;
		s[hv[0].back().second] += k;
		s[hv[1].back().second] -= k;
		while(hv[0].size() && hv[0].back().first == 0)hv[0].pop_back();
		while(hv[1].size() && hv[1].back().first == 0)hv[1].pop_back();
		ans += k;
	}
	if(hv[0].size()){
		for(int i=0;i<n;i++){
			while(hv[0].size() && s[i] - x[i] > 0){
				ll k = min(s[i] - x[i] , hv[0].back().first);
				ans += k;
				s[i] -= k;
				hv[0].back().first -= k;
				s[hv[0].back().second] += k;
				while(hv[0].size() && hv[0].back().first == 0)hv[0].pop_back();
			}
		}
	}else if(hv[1].size()){
		for(int i=0;i<n;i++){
			while(hv[1].size() && y[i] - s[i] > 0){
				ll k = min(y[i] - s[i] , hv[1].back().first);
				ans += k;
				s[i] += k;
				hv[1].back().first -= k;
				s[hv[1].back().second] -= k;
				while(hv[1].size() && hv[1].back().first == 0)hv[1].pop_back();
			}
		}
	}
	assert(ans >= 0);
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