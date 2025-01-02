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

	ll st = r - y;
	if(st < l){
		N();
	}

	if(st < k){
		ll dif = k - st;
		ll time = (dif + x - 1)/x;
		time = min(time , t);
		t -= time;
		k = k - time * x;
		if(k < l)N();
		if(t == 0)Y();
	}
	// cerr << k << ' ' << t << '\n';
	for(int i=1;i<=10*x;i++){
		if(!t)Y();
		k += y;
		k -= x;
		t--;
		ll dif = k - st;
		ll time = (dif + x - 1)/x;
		time = min(time , t);
		time = max(time , 0LL);
		t -= time;
		k = k - time * x;
		// cerr << k << ' ' << t << '\n';
		if(k < l)N();
		if(t == 0)Y();
	}
	ll dif = x - y;
	// cerr << k << ' ' << t << ' ' << dif << '\n';
	if(dif * t > k - l)N();
	Y();
}