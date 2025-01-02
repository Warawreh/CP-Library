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
		int o=0,b=0;
		vector<int> h(2);
		int ans = 0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			o += a%2;
			if(a % 2 != i % 2){
				if(h[!(a%2)]){
					h[!(a%2)]--;
					ans++;
				}else{
					h[a%2]++;
				}
			}
		}
		cout << (h[0] || h[1] ? -1 : ans) << '\n';
	}
}