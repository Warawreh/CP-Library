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
		vector<vector<int>> e;
		int g = ceil(sqrt(n));
		int t = n;
		for(int i=n-1;i>=2;i--){
			if(g == i){
				e.push_back({t,g});
				e.push_back({t,g});
				// cerr << t << ' ' << g << '\n';
				t = g;
				g = ceil(sqrt(t));
			}else{
				e.push_back({i,t});
			}
		}
		// int a = n;
		// int b = g;
		// while(1){
		// 	// cerr << "Before : " << a << ' ' << b << '\n';
		// 	if(a >= b){
		// 		e.push_back({n,g});
		// 		a = (a + b - 1)/b;
		// 	}else{
		// 		e.push_back({g,n});	
		// 		b = (a + b - 1)/a;
		// 	}
		// 	// cerr << "After : " << a << ' ' << b << '\n';
		// 	if(a == 1 || b == 1)break;
		// }
		assert(e.size() <= n + 5);
		cout << e.size() << '\n';
		for(auto a : e){
			cout << a[0] << ' ' << a[1] << '\n';
		}
	}
}