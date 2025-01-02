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
	freopen("tank.in","r",stdin);	
	int t;
	cin>>t;
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll mn = 1e18;
		pair<int,int> res;
		for(ll i=0;i<=a;i++){
			ll cur = i * b;
			ll need = a - cur;
			need = (need + c - 1) / c;
			need *= c;
			if(cur + need - a < mn){
				res = {i , need / c};
				mn = cur + need - a;
			}
			if(cur > a)break;
		}
		cout << res.first << ' ' << res.second << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/