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
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans = 0;
		for(int i=2;i<=2*n;i++){
			vector<int> tmp(2*n + 1);
			for(int j=0;j<n;j++)tmp[a[j]]++;
			int cur = 0;
			for(int j=1;j<=i/2;j++){
				if(j == i-j){
					cur += tmp[j] / 2;
				}else{
					cur += min(tmp[j] , tmp[i - j]);
				}
			}
			ans = max(ans , cur);
		}
		cout << ans << '\n';
	}	
}