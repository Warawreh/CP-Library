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
		int n,m;
		cin>>n>>m;
		vector<int> ways(n + m + 10);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ways[i+j]++;
			}
		}
		int mx = 0;
		vector<int> ans;
		for(int i=1;i<=n+m;i++){
			if(ways[i] > mx){
				ans.clear();
				mx = ways[i];
				ans.push_back(i);
			}else if(ways[i] == mx){
				ans.push_back(i);
			}
		}
		for(int i : ans)cout << i << '\n';
	}