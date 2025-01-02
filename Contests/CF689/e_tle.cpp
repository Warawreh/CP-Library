#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void Y(){
	cout << "Yes\n";
	exit(0);
}

void N(){
	cout << "No\n";
	exit(0);	
}

int main(){
	fast
	ll k,l,r,t,x,y;
	cin>>k>>l>>r>>t>>x>>y;
	for(int i=0;i<t;i++){
		if(k + y <= r)k += y;
		k -= x;
		if(k < l)N();
	}
	Y();
}