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
		vector<int> x(n);
		for(int i=0;i<n;i++)cin>>x[i];
		for(int i=0;i<n;i++){
			int y;
			cin>>y;
		}
		sort(all(x));
		int ans = 0;
		int l=0,best = 0;
		vector<int> have(n,0);
		for(int i=0;i<n;i++){
			int bf = x[i] - k;
			while(l < i && x[l] < bf){
				best = max(best , have[l++]);
			}
			have[i] = i - l + 1;
			ans = max(ans , best + have[i]);
		}
		cout << ans << '\n';
	}	
}