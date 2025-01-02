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
	int t;
	cin>>t;
	while(t--){
		ll o=0,len = 0,tms = 1e9;
		ll n = 26;
		vector<ll> f(26);
		for(ll i=0;i<n;i++){
			cin>>f[i];
			if(f[i] == 1)o++;
			else if(f[i] >= 2){
				len += 2;
				tms = min(tms , f[i] / 2);
			}
		}
		if(o){
			cout << len + 1 << ' ' << min(tms , o) << '\n';
		}else{
			if(len == 0)tms = 0;
			cout << len << ' ' << tms << '\n';
		}

	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/