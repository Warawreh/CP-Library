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
		int n,x;
		cin>>n>>x;
		vector<int> a(n);
		int even = 0,odd=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]%=2;
			if(a[i])odd++;
		}
		even = n - odd;
		int rest = max(1 , x - even);
		if(rest % 2 == 0 && even){
			rest++;
		}
		if(rest > odd)rest = 0;
		// cerr << odd << ' ' << 
		cout << (rest % 2 ? "Yes\n" : "No\n");
	}
}