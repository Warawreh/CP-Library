#include <bits/stdc++.h>
 
using namespace std;
 
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
vector<int> prime,p;
vector<bool> is_composite;
 
void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int Q;
 
ll ask(ll a){
	if(Q >= 22)return sqrt(a);
	Q++;
	cout << "? " << a << '\n';
	fflush(stdout);
	ll res;
	cin>>res;
	return res;
}
 
void clean(ll cur){
	while(p.size() && cur > (ll)1e9 / p.back() )p.pop_back();
}
 
ll get_nxt(ll cur){
	for(int i=0;i<6;i++){
		if(p.empty())break;
		if(cur > (ll)1e18 / p[0])break;
		cur *= p[0];
		p.erase(p.begin() + 0);
	}
	while(p.size()){
		int at = uniform_int_distribution<int>(0, p.size()-1)(rng);
		if(cur > (ll)1e18 / p[at])break;
		cur *= p[at];
		p.erase(p.begin() + at);
	}
	return cur;
}
 
void solve(){
	Q = 0;
	p = prime;
	vector<int> tmp = p;
	// cerr << prime.size() << '\n';
	ll ans = 1;
	for(int i=1;i<=16;i++){
		ll cur = get_nxt(1);
		ll g = ask(cur);
		ans *= g;
		clean(ans);
	}
	vector<ll> g;
	for(ll i : tmp){
		if(ans % i == 0)g.push_back(i);
	}
	ll res = 1;
	ll val = 1;
	ll A = 1;
	for(ll i : g){
		ll tmp = i;
		while(tmp < (ll)1e9 / i){
			tmp *= i;
			if(A >= (ll)1e18/i){
				ll W = __gcd(val , A);
				val /= W;
				ll X = ask(A);
				val *= X;
				A = tmp;
			}
			A *= i;
		}
	}
	if(A != 1){
		ll X = ask(A);
		val *= X;
	}
	for(ll i : g){
		int cnt = 0;
		// cerr << i << ' ' << x << '\n';
		while(val % i == 0){
			cnt++;
			val /= i;
		}
		res *= (cnt + 1);
	}
	cout << "! " << res << '\n';
	fflush(stdout);
}
 
int main(){
	// fast
	sieve(31624);

	int t;
	cin>>t;
	while(t--)solve();
 
}