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
		int n,k;
		cin>>n>>k;
		vector<int> a(n),b(n);
		for(int &i : a)cin>>i;
		for(int &i : b)cin>>i;
		sort(all(a));sort(all(b));
		int at = 0;
		for(int i=n-1;i>=n-k;i--){
			for(int j=n-1;j>=0;j--){
				if(b[i] > a[j]){
					swap(a[j] , b[i]);
				}
			}
		}
		ll sum = 0;
		for(int i=0;i<n;i++)sum += a[i];
		cout << sum << '\n';
	}
}