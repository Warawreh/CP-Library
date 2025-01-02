#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[1002][2][10][10];
vector<vector<int>> g;
const ll oo = 1e18;
int n,m;

ll calc(int i,int x,int l,int r){
	if(i == n)return 0;
	ll &ret = dp[i][x][l][r];
	if(ret != -oo)return ret;
	ret = calc(i+1,x,m,m);
	for(int nl=0;nl<m;nl++){
		ll sum = 0;
		for(int nr=nl;nr<m;nr++){
			sum += g[i][nr];
			// cerr << i << ' ' << x << ' ' << l << ' ' << r << ' ' << nl << ' ' << nr << ' ' << sum << '\n';

			if(x == 0 || (nl <= r && nr >= l)){
				ret = max(ret , calc(i + 1,1, nl , nr) + sum);
			}
		}
	}

	return ret;
}

void solve(){
	cin>>n>>m;

	g.clear();
	g = vector<vector<int>>(n,vector<int>(m));

	for(int i=0;i<n;i++){
		for(int x=0;x<2;x++)
			for(int l=0;l<=m;l++)
				for(int r=l;r<=m;r++)
					dp[i][x][l][r] = -oo;
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];

	cout << calc(0,0,m,m) << '\n';

}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/