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
	// for(int i=0;i<n;i++)pro[i][i] = 1;
	pro[x][y] = 1;

	if(n == 1){
		cout << 1.0 << '\n';
		return;
	}

	p /= (n-1);

	for(int T=0;T<k;T++){

		vector<vector<ld>> nxt(n,vector<ld>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){

				if(i == j){

					int tot = 2;
					if(j == 0 || j == n-1)tot = 1;

					nxt[i][j] += pro[i][j] * (1 - tot * p);
					if(j)nxt[i][j] += pro[i-1][j-1] * p;
					if(j != n-1)nxt[i][j] += pro[i+1][j+1] * p;

				}else if(abs(i - j) == 1){
					nxt[j][i] += pro[i][j] * p;

					int tot = 3;
					if(j == 0 || i == 0)tot--;
					if(j == n-1 || i == n-1)tot--;

					nxt[i][j] += pro[i][j] * (1 - tot * p);

					if(i < j){
						if(i){
							nxt[i-1][j] += pro[i][j] * p;
						}
						if(j + 1 < n){
							nxt[i][j+1] += pro[i][j] * p;
						}
					}else{
						if(j){
							nxt[i][j-1] += pro[i][j] * p;
						}
						if(i + 1 < n){
							nxt[i+1][j] += pro[i][j] * p;
						}
					}
				}else{
					int tot = 4;
					if(i == 0)tot--;
					if(j == 0)tot--;
					if(i == n-1)tot--;
					if(j == n-1)tot--;

					nxt[i][j] += pro[i][j] * (1 - tot * p);

					{//i
						if(i)nxt[i-1][j] += pro[i][j] * p;
						if(i + 1 < n)nxt[i+1][j] += pro[i][j] * p;
					}

					{//j
						if(j)nxt[i][j-1] += pro[i][j] * p;
						if(j + 1 < n)nxt[i][j+1] += pro[i][j] * p;
					}
				}


			}
		}

		pro = nxt;
		nxt.clear();

	}

	cout << pro[y][x] << '\n';
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