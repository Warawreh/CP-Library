#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(int l,int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

int main(){
	fast
	int l = rnd(1,1e6);
	int r = rnd(l + 1000,2e6);
	int k = rnd(l,r);
	int t = rnd(1,100000);
	int x = rnd(1,100000);
	int y = rnd(1,100000);
	cout << k << ' ' << l << ' ' << r << ' ' << t << ' ' << x << ' ' << y << '\n';
}