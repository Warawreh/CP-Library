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
		ll ans = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			
		}
		for(int it=0;it<n;it++){
			bool done = true;
			for(int i=0;i<n;i++)if(a[i] != 1)done = false;
			if(done)break;
			for(int i=0;i<n;){
				int j = a[i];
				a[i] = max(1 , a[i] - 1);
				i += j;
			}
			ans++;
		}
		cout << ans << '\n';
	}
}