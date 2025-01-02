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
	ll n;
	cin>>n;
	ll ans = 1;	
	vector<int> x(11);
	iota(all(x),1);
	n--;
	for(int i=0;i<=10;i++){
		ans = ans * (n-i);
		for(int j=0;j<x.size();j++){
			if(ans % x[j] == 0){
				ans /= x[j];
				x[j] = 1;
			}
		}
	}
	cout << ans << '\n';
}