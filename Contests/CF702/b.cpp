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
			f[a%3]++;
		}
		int to = n/3;
		int ans = 0;
		for(int it=0;it<10;it++){
			for(int i=0;i<3;i++){
				int move = max(0 , f[i] - to);
				ans += move;
				f[i] -= move;
				f[(i+1)%3] += move;	
			}
		}
		cout << ans << '\n';
	}
}