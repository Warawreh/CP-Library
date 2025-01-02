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
		int n,k;
		cin>>n>>k;
		set<int> a;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			a.insert(x);
		}
		if(k == 1 && a.size() > 1){
			cout << -1 << '\n';
		}else{
			if(k >= a.size()){
				cout << 1 << '\n';
			}else{
				int ans = a.size();
				ans -= k;
				k--;
				cout << (ans + k - 1)/k + 1 << '\n';
			}
		}
	}
}