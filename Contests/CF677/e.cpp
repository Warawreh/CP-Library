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
	int n;
	cin>>n;
	vector<ll> f(n + 2);
	f[0] = 1;
	for(int i=1;i<=n;i++)f[i] = f[i-1] * 1LL * i;
	cout << f[n] / f[n/2] / f[n/2] * f[n/2 - 1] * f[n/2 - 1] / 2 << '\n';
}