#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,x,y,k;
	ld p;
	cin>>n>>p>>x>>y>>k;
	vector<vector<ld>> pro(n,vector<ld>(n,0));
	for(int i=0;i<n;i++)pro[i][i] = 1;

	if(n == 1){
		cout << 1.0 << '\n';
		return;
	}

	p /= (n-1);

	for(int T=0;T<k;T++){

		vector<vector<ld>> nxt(n,vector<ld>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int tot = 2;
				if(j == 0 || j == n-1)tot = 1;

				nxt[i][j] += pro[i][j] * (1 - tot * p);
				if(j)nxt[i][j] += pro[i][j-1] * p;
				if(j != n-1)nxt[i][j] += pro[i][j+1] * p;
			}
		}

		pro = nxt;
		nxt.clear();

	}

	cerr << pro[x][y] << ' ' << pro[y][x] << '\n';

	cout << pro[x][y] << '\n';
}

int main(){
	fast
	cout << setprecision(5) << fixed;

	freopen("assessment.in","r",stdin);
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