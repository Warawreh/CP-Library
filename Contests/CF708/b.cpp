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
		int n,m;
		cin>>n>>m;
		vector<int> f(m);
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			f[a%m]++;
		}
		int ans = 0;
		if(f[0])ans++;
		for(int i=1;i<m/2 + m%2;i++){
			if(f[i] == 0 && f[m-i] == 0)continue;
			if(abs(f[i] - f[m-i]) <= 1)ans++;
			else{
				int mx = max(f[i] , f[m-i]);
				int mn = min(f[i] , f[m-i]);
				ans += mx - mn;
			}
		}
		if(m%2 == 0){
			if(f[m/2])ans++;
		}
		cout << ans << '\n';
	}
}