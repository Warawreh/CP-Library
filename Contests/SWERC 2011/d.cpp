#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	while(1){
		ll n,k;
		cin>>n>>k;
		if(n == -1 && k == -1)break;
		vector<ll> a(n);
		ll mx = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			mx = max(mx , a[i]);
		}
		ll lo=1,hi=mx,ans=mx;
		while(lo <= hi){
			ll md = (lo + hi)/2;
			ll need = 0;
			for(int i=0;i<n;i++){
				need += (a[i] + md - 1)/md;
			}
			if(need <= k){
				hi = md-1;
				ans = md;
			}else{
				lo = md+1;
			}
		}
		cout << ans << '\n';
	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/