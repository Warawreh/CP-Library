#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;

void solve(int C){
	int d,n;
	cin>>d>>n;
	int ans = 0;
	for(int times=0;times<99;times++){
		vector<int> g(n);
		for(int i=0;i<n;i++){
			g[i] = rand();
		}
		for(int i=0;i<n;i++){
			bool can = 1;
			if(i && g[i] < g[i-1])can = 0;
			if(i + 1 < n && g[i] < g[i+1])can = 0;
			ans += can;
		}
	}
	printf("Case %d: %d\n", C , ans);
}

int main(){
	freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		solve(++cnt);
	}	
}