#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()

map<ll,bool> good,used;
map<ll,ll> w;

int main(){
	// freopen("distribution.in" , "r" , stdin);
	// freopen("distribution.out" , "w" , stdout);
	vector<ll> num;
	vector<pair<ll,ll>> num2;
	ll cur = 1;
	for(int i=0;i<64;i++){
		ll tmp = cur;
		for(int j=0;j<64;j++){
			num.push_back(tmp);
			good[tmp] = 1;
			if(tmp > (1e18+2)/3)break;
			tmp *= 3;
		}
		if(cur > (1e18/2))break;
		cur *= 2;
	}
	sort(all(num));
	for(ll x : num){
		for(ll y : num){
			if(y % x == 0 || y % x == 0)continue;
			w[x + y] = x;
		}
	}
	int t;
	cin>> t;
	while(t--){
		ll n;
		cin>>n;
		ll v=1;
		if(good[n]){
			cout << 1 << '\n' << n << '\n';
			continue;
		}
		while(n%2==0){
			v*=2;
			n/=2;
		}
		while(n%3==0){
			v*=3;
			n/=3;
		}
		vector<ll> ans;
		// cout << n << '\n';
		for(ll x : num){
			if(x > n)break;
			if(good[n-x] && x % (n-x) && (n-x)%x){
				ans.push_back(x);
				ans.push_back(n-x);
				break;
			}
			ll a = w[n-x];
			ll b = n-x-w[n-x];
			if(w[n-x] && x % a && x % b && a % x && a % b && b % x && b % a){
				ans.push_back(x);
				ans.push_back(a);
				ans.push_back(b);
				break;
			}
		}
		if(ans.empty()){
			
		}
		cout << ans.size() << '\n';
		for(ll i : ans)
			cout << i*v << ' ';
		cout << '\n';
	}
}