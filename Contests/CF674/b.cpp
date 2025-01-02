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
		bool good = 0;
		for(int i=0;i<n;i++){
			vector<int> a(2),b(2);
			cin>>a[0]>>a[1]>>b[0]>>b[1];

			if(a == b && a[0] == a[1] || a[1] == b[0]){
				good = 1;
			}
		}
		// cerr << good << '\n';
		good &= (m % 2 == 0);
		cout << (good ? "YES\n" : "NO\n");
	}
}