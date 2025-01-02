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
		vector<int> c(n);
		vector<vector<int>> e;
		int with = -1;
		for(int i=0;i<n;i++){
			cin>>c[i];
			if(c[i] != c[0]){
				with = i;
				e.push_back({0 , i});
			}
		}
		if(with == -1){
			cout << "NO\n";
		}else{
			for(int i=1;i<n;i++){
				if(c[i] == c[0]){
					e.push_back({with,i});
				}
			}
			cout << "YES\n";
			for(vector<int> a : e){
				cout << a[0] + 1 << ' ' << a[1] + 1 << '\n';
			}
		}
	}
}