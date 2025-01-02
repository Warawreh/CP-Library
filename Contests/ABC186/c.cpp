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
	int n;
	cin>>n;
	int ans = 0;
	for(int i=1;i<=n;i++){
		int a = i;
		bool good = true;

		while(a){
			if(a % 10 == 7)good = false;
			a /= 10;
		}

		a = i;
		while(a){
			if(a % 8 == 7)good = false;
			a /= 8;
		}

		ans += good;
	}
	cout << ans << '\n';
}