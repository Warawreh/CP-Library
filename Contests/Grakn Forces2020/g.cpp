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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	int u=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i && a[i] != a[i-1])u++;
	}
	if(k == 1 && a[0] != a[n-1]){
		cout << -1 << '\n';
	}else{
		int ans = 1;
		u -= k;
		if(k > 1){
			ans += (u +k-)
		}
	}
}