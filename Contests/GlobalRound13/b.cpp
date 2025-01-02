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
		ll n,u,v;
		cin>>n>>u>>v;
		vector<int> a(n);
		bool good = false,same = true;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i && abs(a[i] - a[i-1]) > 1){
				good = true;
			}
			if(a[i] != a[0])same = false;
		}
		if(good){
			cout << 0 << '\n';
		}else if(same){
			cout << min(2*v,u+v) << '\n';
		}else{
			cout << min(u,v) << '\n';
		}
	}
}