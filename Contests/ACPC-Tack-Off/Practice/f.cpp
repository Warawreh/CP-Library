#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll have(ll y){
	return (y / 4) - (y / 100) + (y / 400); 
}

int main(){
	fast
	freopen("stars.in","r",stdin);
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
		ll l,r;
		cin>>l>>r;
		cout << have(r) - have(l-1) << '\n';
	}
}