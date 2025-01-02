#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(all(a));
	
	if(k + k < n){
		cout << "NO\n";
		return;
	}
	for(int i=2;i<n;i++){
		if(a[i] == a[i-2]){
			cout << "NO\n";
			return;		
		}
	}
	cout << "YES\n";
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}