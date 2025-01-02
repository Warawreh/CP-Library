#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt = 0;
		for(int x=0;x<(1<<(n));x++){
			for(int y=x;y<(1<<(n));y++){
				int z = (x^y);
				if(__builtin_popcount(z) % 2){
					// if(n == 1){
					// 	cerr << x << ' ' << y << '\n';
					// }
					cnt++;
				}
			}
		}
		cout << cnt % mod << '\n';
		
	}
}