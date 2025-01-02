#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n,t;
	cin>>n>>t;
	vector<int> a,b;
	bool z = 0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x == 0)z = 1;
		if(x < 0)a.push_back(-x);
		else if(x > 0) b.push_back(x);
	}
	a.push_back(0);
	sort(all(a));
	sort(all(b));
	int ans = 0;
	for(int i=0;i<a.size();i++){
		if(a[i] > t)continue;
		int rest = t - 2*a[i];
		int to = upper_bound(all(b) , rest) - b.begin();
		// cout << a[i] << ' ' << rest << ' ' << to << '\n';
		ans = max(ans , i + to);
	}
	a.erase(a.begin());
	b.insert(b.begin(),0);
	for(int i=0;i<b.size();i++){
		if(b[i] > t)continue;
		int rest = t - 2*b[i];
		int to = upper_bound(all(a) , rest) - a.begin();
		// cout << a[i] << ' ' << rest << ' ' << to << '\n';
		ans = max(ans , i + to);
	}
	cout << ans + z << '\n';
}