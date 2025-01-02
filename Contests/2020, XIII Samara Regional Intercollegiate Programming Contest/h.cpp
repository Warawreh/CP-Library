#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n;
	cin>>n;
	vector<int> in(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		in[u]++;in[v]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++)ans += in[i] == 1;
	cout << (ans + 1)/2 << '\n';
}