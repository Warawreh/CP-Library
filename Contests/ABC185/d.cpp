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
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	for(int i=0;i<m;i++)cin>>a[i];
	a.push_back(0);
	a.push_back(n + 1);
	sort(all(a));
	int len = n;
	for(int i=1;i<a.size();i++){
		// cerr << a[i] << ' ' << a[i-1] << '\n';
		if(a[i] > a[i-1] + 1)
			len = min(len , a[i] - a[i-1] - 1);
	}
	if(len == 0){
		cout << 0 << '\n';
		return 0;
	}
	ll ans = 0;
	for(int i=1;i<a.size();i++){
		// cerr << a[i] << ' ' << a[i-1] << '\n';
		if(a[i] > a[i-1] + 1){
			int c = a[i] -a[i-1] - 1;
			ans += (c + len - 1)/len;
		}
	}
	cout << ans << '\n';
}