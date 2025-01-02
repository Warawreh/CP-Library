#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(ll x){
	cout << x << '\n';
	fflush(stdout);
	int res;
	cin>>res;
	return res;
}

int main(){
	// fast
	ll a,b,c;
	cin>>a>>b>>c;
	vector<pair<ll,ll>> x = {{a,1},{b,2},{c,3}};
	cout << "First\n";
	fflush(stdout);
	sort(all(x));
	ll to = 2*x[2].first - x[1].first - x[0].first;
	int res = ask(to);
	if(res == x[0].second){
		ask(x[2].first - x[1].first);
	}else if(res == x[1].second){
		ask(x[2].first - x[0].first);
	}else{
		x[2].first += to;
		ll to = 2*x[2].first - x[1].first - x[0].first;
		int res = ask(to);
		if(res == x[0].second){
			ask(x[2].first - x[1].first);
		}else if(res == x[1].second){
			ask(x[2].first - x[0].first);
		}
	}
}