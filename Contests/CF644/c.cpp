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
		vector<int> a(n);
		vector<vector<int>> p(2);
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			p[a%2].push_back(a);
		}
		if(p[0].size() % 2){
			bool good = 0;
			for(int i : p[0]){
				for(int j : p[1]){
					if(abs(i - j) == 1)good = 1;
				}
			}
			cout << (good ? "YES\n" : "NO\n");
		}else{
			cout << "YES\n";
		}
	}
}