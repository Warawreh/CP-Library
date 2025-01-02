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
		vector<int> s,b(2*n+1);
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]] = 1;
		}
		for(int i=1;i<=2*n;i++)if(!b[i])s.push_back(i);
		int l =0,r=n;
		for(int i=1;i<=n;i++){
			int at = lower_bound(all(s) , a[i]) - s.begin();
			at--;
			int dif = i - at - 1;
			dif = max(dif , 0);
			// cerr << at << ' ' << dif << ' ' << n-at-1 + i-1 << '\n';
			l = max(l , dif);
			r = min(r , n-at-1 + i-1);
		}
		// cerr << l << ' ' << r << '\n';
		cout << max(0 , r - l+1) << '\n';
	}
}