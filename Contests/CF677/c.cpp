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
		int mx = 0,mn = 2e9;
		int at = -1;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			a[i] = x;
			mn = min(mn , x);
			mx = max(mx , x);
		}
		if(mn == mx)cout << -1 << '\n';
		else{
			for(int i=0;i<n;i++){
				if(a[i] != mx)continue;
				if(i && a[i-1] < a[i]){
					cout << i + 1 << '\n';
					break;
				}
				if(i + 1 < n && a[i + 1] < a[i]){
					cout << i +1 << '\n';
					break;
				}
			}
		}
	}
}