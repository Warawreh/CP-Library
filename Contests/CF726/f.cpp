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
		int n,m;
		cin>>n>>m;
		vector<int> a(n),b(n);
		ll ns = 0,ps = 0;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++){
			cin>>b[i];
			if(a[i] - b[i] < 0)ns -= a[i] - b[i];
			else ps += a[i] - b[i];
		}
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
		}
		cout << ((ns%2 == 0 && ps%2==0) ? "Yes\n" : "No\n");
	}
}