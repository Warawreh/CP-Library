#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	cin>>n;
	vector<ll> a(n);
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += (i + 1) * a[i];
	}

	ll ans = sum;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans = max(ans , sum - (i+1) * a[i] - (j+1) * a[j] + (j+1) * a[i] + (i+1) * a[j]);
		}
	}
	cout << ans << '\n';
}

int main(){
	fast
	freopen("func.in","r",stdin);
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/