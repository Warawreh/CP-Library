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
		ll sum = 0,x=0;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum += a[i];
			if(i%2 == 1)x += a[i] - 1;
		}
		if(x * 2 <= sum){
			for(int i=0;i<n;i++){
				if(i % 2 ==0 )cout << a[i] << ' ';
				else cout << 1 << ' ';
			}
		}else{
			x = 0;
			for(int i=0;i<n;i++){
				if(i % 2 == 1)cout << a[i] << ' ';
				else{
					x += a[i] - 1;
					cout << 1 << ' ';
				}
			}
		}
		assert(x * 2 <= sum);
		// cerr << sum << '\n';
		cout << '\n';
	}
}