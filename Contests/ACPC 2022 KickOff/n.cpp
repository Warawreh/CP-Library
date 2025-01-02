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
	freopen("machines.in","r",stdin);	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll need = n / 84;
		need *= 48;
		n %= 84;

		vector<int> dp(84+84,1e9);
		dp[0] = 0;
		vector<int> move = {1,3,4,7};
		vector<int> cost = {1,2,3,4};
		for(int i=0;i<4;i++){
			for(int j=move[i];j<dp.size();j++){
				dp[j] = min(dp[j] , dp[j - move[i]] + cost[i]);
			}
		}
		int extra = dp[n];
		for(int i=n;i<dp.size();i++)extra = min(extra , dp[i]);

		cout << need + extra << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/