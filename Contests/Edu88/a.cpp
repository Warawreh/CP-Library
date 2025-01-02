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
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x = n/k;
		if(m <= x)cout << m << '\n';
		else{
			int rem = m - x;
			rem = (rem + k - 2)/(k-1);
			cout << x - rem << '\n';
		}
	}
}