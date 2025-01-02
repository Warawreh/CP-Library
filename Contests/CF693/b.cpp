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
		vector<int> f(3);
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			f[a]++;
		}
		if(f[2] % 2 == 1){
			if(f[1] >= 2){
				f[1]-=2;
				f[2]++;
			}
		}
		cout << (f[2] % 2 == 0 && f[1] % 2 == 0 ? "Yes\n" : "No\n");
	}
}