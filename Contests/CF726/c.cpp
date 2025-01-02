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
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(all(a));
		int mn = a.back() + 1;
		int to = 0;
		for(int i=1;i<n;i++){
			if(a[i] - a[i-1] < mn){
				mn = a[i] - a[i-1];
				to = i-1;
			}
		}
		swap(a[to] , a[to+1]);
		for(int i=to + 1;i<n;i++)cout << a[i] << ' ';
		for(int i=0;i<=to;i++)cout << a[i] << ' ';
		cout << '\n';
	}
}