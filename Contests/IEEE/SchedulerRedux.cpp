#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2e5 + 2;
const int mod = 1e9 + 7;

ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}

int main(){
    fast
    int n,m;
    cin>>n>>m;
    vector<bitset<nax>> v(m);
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
	reverse(all(a));

	int at = 0;
	for(int i=0;i<n;i++){
		int c = a[i];
		while(v[at][c] == 1){
			v[at][c] = 0;
			c++;
		}
		v[at][c] = 1;
		if(at == 0 || (v[at] & v[at-1]) == v[at])at = (at + 1)%m;
	}

	ll ans = 0;
	for(int i=nax-1;i>=0;i--){
		if(v[0][i] == 1)ans = (ans + POW(2 , i))%mod;
	}
	cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/