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
		vector<int> a(n),f(2*n + 3);
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]--;
			f[a[i]]++;
		}
		int ans = 0;
		for(int i=0;i<=2*n;i++){
			f[i] = min(f[i] , 2);
			if(f[i]){
				ans++;
				f[i]--;
			}
			if(f[i])f[i+1] += f[i];
		}
		cout << ans << '\n';
	}
}