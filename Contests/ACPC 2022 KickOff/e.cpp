#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	ll h,v,t;
	cin>>h>>v>>t;

	ld x = sqrt(t * t - v * v);
	x = min(x , (ld)h);
	cout << sqrt(x * x + v * v) + h - x << '\n';
}

int main(){
	fast
	freopen("cross.in","r",stdin);	
	cout << setprecision(20) << fixed;
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/