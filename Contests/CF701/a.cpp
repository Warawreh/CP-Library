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
		int a,b;
		cin>>a>>b;
		int ans = 1e9;
		for(int i=b;i<=b+50;i++){
			if(i == 1)continue;
			int need = 0;
			int tmp = a;
			while(tmp > 0){
				need++;
				tmp /= i;
			}
			ans = min(ans , i - b + need);
		}
		cout << ans << '\n';
	}
}