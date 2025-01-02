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
	int n=2,k=3;
	while(t--){
		cin>>n>>k;
		// n++;
		int x = n/2;
		n -= k - 3;
		for(int i=0;i<k-3;i++)cout << 1 << ' ';
		k = 3;
		if(n%2){
			x = n/2;
		}
		else if(n%4 == 0){
			x = n/4;
		}
		else{
			x = 1;
			int tmp = n;
			while(1){
				if(tmp%2 == 1){
					break;
				}
				x*=2;
				tmp/=2;
			}
		}
		if(x * (n-2*x) / gcd(x,n-2*x) * 2 <= n){
			cout << x << ' ' << x << ' ' << n - 2*x << '\n';
		}
		else{
			x = n/2-1;
			if(x * (n-2*x) / gcd(x,n-2*x) * 2 <= n){
				cout << x << ' ' << x << ' ' << n - 2*x << '\n';
			}else{
				assert(0);
			}
		}
		
	}
}