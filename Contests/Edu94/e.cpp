#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a;

int solve(int l,int r){
	if(l > r)return 0;
	if(l == r)return 1;
	int mn = a[l];
	for(int i=l;i<=r;i++)mn = min(mn , a[i]);
	int lst = l;
	int res = mn;
	for(int i=l;i<=r;i++){
		a[i] -= mn;
		if(!a[i]){
			res += solve(lst,i-1);
			lst = i + 1;
		}
	}
	res += solve(lst , r);
	return min(res, r - l + 1);
}

int main(){
	fast
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	cout << solve(0,n-1) << '\n';
}