#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll oo = 1e18;

void solve(){
	int n;
	cin>>n;
	vector<ll> p(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}

	vector<vector<ll>> dp(n+1,vector<ll>(n+1,oo));

	dp[0][0] = 0;
	for(int c=1;c<=n;c++){
		for(int t=1;t<=n;t++){

			for(int g=1;g<=c;g++){
				int rem = c - g;
				if(rem < t-1)continue;
				dp[t][c] = min(dp[t][c] , dp[t-1][rem] + p[g]);
			}

		}
	}

	cout << '\n';
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>b>>a;

		if(a > b)cout << "impossible\n";
		else cout << dp[a][b] << '\n';
	}

}

int main(){
	fast
	freopen("jacking.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ": ";
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/