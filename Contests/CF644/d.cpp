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
		int n,k;
		cin>>n>>k;
		int ans = 2e9;
		for(int i=1;i*i<=n;i++){
			if(i > k)break;
			if(n % i)continue;
			ans = min(ans , n/i);
			if(n/i <= k){
				ans = min(ans , i);
			}
		}
		cout << ans << '\n';
	}
}