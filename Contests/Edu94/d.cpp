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
		vector<int> a(n);
		vector<vector<ll>> dp(2,vector<ll>(n));
		vector<vector<ll>> cnt(n,vector<ll>(n)),c(n,vector<ll>(n)),use(n,vector<ll>(n));
		ll ans = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]--;
			ll sum = 0;
			for(int j=i-1;j>=0;j--){
				cnt[a[i]][a[j]]++;
				c[i][a[j]]++;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans += use[a[j]][a[i]];
			}
			for(int j=0;j<n;j++)use[a[i]][j] += c[i][j];
		}
		cout << ans << '\n';
	}
}