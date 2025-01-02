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
		int n;
		cin>>n;
		ll sum = 0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			sum += x;
		}
		if(sum == n)cout << 0 << '\n';
		else if(sum < n)cout << 1 << '\n';
		else cout << sum - n << '\n';
	}
}