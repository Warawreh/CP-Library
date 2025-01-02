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
		vector<int> a(n),f(n+1);
		for(int i=0;i<n;i++){
			cin>>a[i];
			f[a[i]]++;
		}
		sort(all(f));
		int sum = 0;
		int at = f.back();
		for(int i=n;i>=0;i--){
			sum += max(0,min(at , f[i]));
			at = min(at , f[i]) - 1;
		}
		cout << sum << '\n';
	}
}