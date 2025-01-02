#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n;
	cin>>n;
	ll ans = 0,worst=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ans += x;
		worst = min(worst , ans);
	}
	cout << -worst << '\n';
}