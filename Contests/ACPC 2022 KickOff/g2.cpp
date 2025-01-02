#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 65;
ll dp[nax][nax][2];
ll x;
ll calc(ll i,int r,bool e){
	if(r < 0)return 0;
	if(i == -1){
		return (r == 0);
	}
	ll &ret = dp[i][r][e];
	if(ret != -1)return ret;
	ret = 0;
	if(e == 0){
		ret = calc(i-1,r,0) + calc(i-1,r-1,0);
	}else{
		if((x >> i) & 1){
			ret = calc(i-1,r-1,1) + calc(i-1,r,0);
		}else{
			ret = calc(i-1,r,1);
		}
	}
	return ret;
}

int main(){
	fast
	freopen("hotel.in","r",stdin);	
	
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;

		ll lo=1,hi = 1e18,ans=-1;
		while(lo <= hi){
			ll md = (lo + hi)/2;

			x = md;
			memset(dp,-1,sizeof(dp));
			ll val = calc(63,k,1);

			x = md*2;
			memset(dp,-1,sizeof(dp));
			val = calc(63,k,1) - val;
			// cerr << val << ' ' << md << ' ' << x << ' ' << calc(63,k,1) << '\n';
			if(val == n){
				ans = md;
				break;
			}
			if(val > n)hi = md-1;
			else lo = md+1;
		}
		assert(ans != -1);
		cout << ans << '\n';

	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/