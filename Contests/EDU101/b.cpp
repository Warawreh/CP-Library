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
		int s1 = -1e9,s2 = -1e9,cur = 0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			cur += a;
			s1 = max(s1 , cur);
		}
		cur = 0;
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			int a;
			cin>>a;
			cur += a;
			s2 = max(s2 , cur);
		}
		cout << max({0 , s1 + s2,s1,s2}) << '\n';
	}
}