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
	int n;
	cin>>n;
	vector<ll> a(n);
	vector<vector<ll>> ans(3);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(n == 1)break;
		if(i == 0){
			ans[0].push_back(-a[i]);
			a[i] = 0;
		}else{
			ll cur = a[i]%n;
			ans[1].push_back(cur * (n - 1));
			a[i] += cur * (n - 1);
		}
		assert(a[i] % n == 0);
		ans[2].push_back(-a[i]);
	}
	if(n == 1){
		cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << '\n';
		return 0;
	}
	vector<pair<int,int>> r = {{1,1} , {2,n} , {1,n}};
	for(int i=0;i<3;i++){
		cout << r[i].first << ' ' << r[i].second << '\n';
		for(ll j : ans[i])cout << j << ' ';
		cout << '\n';
	}
}