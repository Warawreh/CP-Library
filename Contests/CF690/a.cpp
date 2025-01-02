#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	for(int i=1;i<=50;i++)
		cout << 45 << '\n';
	return 0;
	fast
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		for(int i=0;i<n/2;i++){
			a[i*2] = b[i];
		}
		int at = 1;
		for(int i=n-1;i>=n/2;i--){
			a[at] = b[i];
			at+=2;
		}
		if(n % 2)a.back() = b[n/2];
		for(int i : a)
			cout << i << ' ';
		cout << '\n';
	}
}