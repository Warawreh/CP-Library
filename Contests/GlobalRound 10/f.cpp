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
	vector<ll> a(n);
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}

	ll lo = 1,hi=1e12,st=1,x=0;
	while(lo <= hi){
		ll md = (lo + hi)/2;
		ll cur = (n)* (md + md + n - 1) / 2;
		if(cur < sum){
			lo = md + 1;
		}else if(cur >= sum){
			hi = md - 1;
			st = md;
			x = cur - sum;
		}
	}
	x = n-x;
	for(int i=0;i<n;i++){
		cout << st - (i >= x) << ' ';
		st++;
	}
	cout << '\n';
}