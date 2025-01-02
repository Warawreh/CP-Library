#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll solve1(ll n,ll k){
	ll ans = 1e18;
	if(n <= 2 || n <= k){
		// cout << 1 << '\n';
		return 1;
	}
	ll kk = k;
	for(int use=1;use<k;use++){
		k = kk;
		k -= use;
		ll watch = use;
		watch += min(watch , (ll)(n - watch)/2);
		ll day = 1;
		while(1){
			day++;
			if(n - watch <= k)break;
			if(k > 1 && (n - watch) % 2){
				watch++;
				k--;
			}
			watch += min(watch , (ll)(n - watch)/2);
			// cerr << day << ' ' << watch << ' ' << k << '\n';
		}
		
		// cerr << day << '\n';
		ans = min(day , ans);
	}
	return ans;
}

ll solve2(ll n,ll k){
	ll ans = 1e18;
	if(n <= 2 || n <= k){
		// cout << 1 << '\n';
		return 1;
	}
	ll kk = k;
	for(int use=1;use<k;use++){
		k = kk;
		k -= use;
		ll watch = use;
		watch += min(watch , (ll)(n - watch)/2);
		ll day = 1;
		while(1){
			day++;
			if(n - watch <= k)break;
			if(k > 1 && (n - watch) % 2 && watch * 2 >= n){
				watch++;
				k--;
			}
			watch += min(watch , (ll)(n - watch)/2);
			// cerr << day << ' ' << watch << ' ' << k << '\n';
		}
		
		// cerr << day << '\n';
		ans = min(day , ans);
	}
	return ans;
}

ll solve3(ll n,ll k){
	ll ans = 1e18;
	if(n <= 2 || n <= k){
		// cout << 1 << '\n';
		return 1;
	}
	ll kk = k;
	for(int use=1;use<k;use++){
		k = kk;
		k -= use;
		ll watch = use;
		watch += min(watch , (ll)(n - watch)/2);
		ll day = 1;
		while(1){
			day++;
			if(n - watch <= k)break;
			if(k > 1 && (n - watch) % 2 && watch * 3 >= n){
				watch++;
				k--;
			}
			watch += min(watch , (ll)(n - watch)/2);
			// cerr << day << ' ' << watch << ' ' << k << '\n';
		}
		
		// cerr << day << '\n';
		ans = min(day , ans);
	}
	return ans;
}

ll solve4(ll n,ll k){
	ll ans = 1e18;
	if(n <= 2 || n <= k){
		// cout << 1 << '\n';
		return 1;
	}
	ll kk = k;
	for(int use=1;use<k;use++){
		k = kk;
		k -= use;
		ll watch = use;
		watch += min(watch , (ll)(n - watch)/2);
		ll day = 1;
		while(1){
			day++;
			if(n - watch <= k)break;
			watch += min(watch , (ll)(n - watch)/2);
			// cerr << day << ' ' << watch << ' ' << k << '\n';
		}
		
		// cerr << day << '\n';
		ans = min(day , ans);
	}
	return ans;
}

const int nax = 110;
int dp[nax][nax];
ll n;

int calc(int r,int k){
	if(r >= n)return 0;
	if(k == 0)return 1e9;
	int &ret = dp[r][k];
	if(ret != -1)return ret;
	ret = 1e9;
	for(int i=0;i<=k;i++){
		ll nr = r + i;
		nr += min(nr , (n - nr)/2);
		ret = min(ret , 1 + calc(nr , k - i));
		// if(r == 0)cerr << 1 + calc(nr , k - i) << ' ' << i << '\n';
	}
	return ret;
}

void build(int r,int k){
	if(r >= n)return;
	cerr << r << ' ' << k << '\n';
	for(int i=!r;i<=k;i++){
		ll nr = r + i;
		nr += min(nr , (n - nr)/2);
		cerr << '-' << i << '\n';
		if(calc(r,k) == 1 + calc(nr , k - i)){
			cout << i << ' ' ;
			build(nr , k - i);
			return;
		}
	}
}

ll solve5(ll n,ll k){
	::n = n;
	memset(dp,-1,sizeof(dp));
	// cout << calc(0,k) << '\n';
	// build(0,k);
	// cout << '\n';
	return calc(0,k);
}

int main(){
	fast
	// cout << solve5(69,6) << '\n';
	// return 0;
	ll n,k;
	cin>>n>>k;
	cout << min({solve1(n,k) , solve2(n,k) , solve3(n,k) , solve4(n,k)});
	// while(1){
	// 	ll n = uniform_int_distribution<long long>(1, (ll)1000000)(rng);
	// 	ll k = uniform_int_distribution<int>(2, n - 1)(rng);
	// 	if(solve2(n,k) != solve4(n,k)){
	// 		cout << n << ' ' << k << '\n';
	// 		cout << solve4(n,k) << ' ' << solve2(n,k) << '\n';
	// 		break;
	// 	}
	// }
}