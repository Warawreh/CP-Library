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
		ll w,h,n;
		cin>>w>>h>>n;
		ll hv = 1;
		while(hv < n){
			if(w % 2 == 0){
				hv *= 2;
				w/=2;
			}else if(h % 2 == 0){
				hv *= 2;
				h /= 2;
			}else break;
		}
		cout << (hv >= n ? "Yes\n" : "No\n");
	}
}