#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> prime;
vector<bool> is_composite;

void sieve (ll n) {
	prime.clear();
	is_composite = vector<bool>(n+1);
	for(ll i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(ll j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

ll answer = 10;
ll n;
ll have_q = 1e4;

ll ask(ll x,ll t){
	if(x == 1)t = 0;
	have_q--;
	assert(have_q >= 0);
	ll res = 0;
	if(t == 0){
		cout << "A " << x << '\n';
		fflush(stdout);
	}else if(t == 1){
		cout << "B " << x << '\n';
		fflush(stdout);
	}
	cin>>res;
	return res;
}

void print(ll ans){
	cout << "C " << ans << '\n';
	fflush(stdout);
}

int main(){
	// fast
	cin>>n;

	sieve(n);
	ll Z = sqrt(prime.size());
	ll should_be = n;
	ll ans = 1;
	ll lst = 0;
	for(ll i=0;i<prime.size();i++){
		if(prime[i] * ans > n)break;
		if(i && i%Z == 0){
			ll have = ask(1,0);
			// cerr << should_be << ' ' << have << '\n';
			if(have != should_be){
				for(ll j=lst;j<i;j++){
					ll val = prime[j];
					while(ans * prime[j] <= n){
						// cerr << ans << ' ' << val << ' ' << n << '\n';
						ll cur = ask(val , 1);
						have -= cur;
						if(cur){
							ans *= prime[j];
						}else break;
						val *= prime[j];
					}
				}
			}
			should_be = have;
			lst = i;
		}
		ll cur = prime[i];
		should_be -= ask(cur,1);
		// cerr << should_be << '\n';
	}
	for(int j=lst;j<prime.size();j++){
		ll val = prime[j];
		while(ans * prime[j] <= n){
			// cerr << ans << ' ' << val << ' ' << n << '\n';
			if(ask(val , 1)){
				ans *= prime[j];
			}else break;
			val *= prime[j];
		}
	}
	print(ans);
}