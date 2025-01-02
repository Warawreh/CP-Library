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
	// cout ;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int mx = -1;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			a--;
			if(a != i)mx = max(mx , a);
		}
		ld x = 1;
		for(int i=0;i<m;i++){
			int to;
			ld p;
			cin>>to>>p;
			to--;
			if(to >= mx){
				x *= (1-p);
			}
		}
		// cerr << x << '\n';
		if(mx == -1){
			cout << 1 << '\n';
		}else{
			cout << setprecision(12) << fixed << 1 - x << '\n';
		}
	}
}