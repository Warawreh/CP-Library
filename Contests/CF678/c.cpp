#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

int main(){
	fast
	int n,x,p;
	cin>>n>>x>>p;
	int lo=0,hi=n;
	int l=x-1,r = n - x;
	ll ans = 1;
	while(lo < hi){
		int md = (lo + hi)/2;
		if(md <= p){
			if(md != p){
				ans = (ans * l)%mod;
				l--;
			}
			lo = md + 1;
		}else{
			ans = (ans * r)%mod;
			r--;
			hi = md;
		}
	}
	for(int i=1;i<=l+r;i++)ans = (ans * 1LL * i)%mod;
	cout << ans << '\n';
}