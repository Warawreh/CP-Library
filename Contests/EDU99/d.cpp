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
		int n,x;
		cin>>n>>x;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		vector<int> b = a,c = a;
		int tx = x;
		int at = 0;
		int ans = 1e9;
		for(int it=0;it<=n;it++){
			sort(all(c));
			int cur = 0;
			// for(int i : c)
			// 	cerr << i << ' ';
			// cerr << '\n';
			for(int i=0;i<n;i++){
				if(c[i] == a[i])continue;
				else{
					// cerr << i << ' ' << a[i] << ' ' << x << '\n';
					if(c[i] == x && a[i] > x){
						cur++;
						swap(a[i] , x);
					}else{
						cur = 1e9;
						break;
					}
				}
			}
			ans = min(ans , cur);
			if(at == a.size())break;

			a = c = b;
			x = tx;
			c[at] = x;

			at++;
		}
		if(ans == 1e9)ans = -1;
		cout << ans << '\n';
	}
}