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
		vector<int> ans;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i >= 2){
				if(a[1] + a[0] <= a[i]){
					ans = {1 , 2 , i+1};
				}
			}
		}
		if(ans.empty())cout << -1 << '\n';
		else cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	}	
}