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
	int n,m;
	cin>>n>>m;
	int mn = 1001,sum = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			mn = min(a, mn);
			sum += a;
		}
	}
	cout << sum - n*m*mn << '\n';
}