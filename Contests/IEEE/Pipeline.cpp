#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m,d;
	cin>>n>>m>>d;
	vector<vector<vector<int>>> g(d,vector<vector<int>>(n,vector<int>(m,3)));
	vector<vector<vector<bool>>> vis(d,vector<vector<bool>>(n,vector<bool>(m,0)));
	for(int i=0;i<d;i++){
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			for(int k=0;k<m;k++){
				if(s[k] == '#')g[i][j][k] = 0;
				else if(s[k] == '*')g[i][j][k] = 3;
				else g[i][j][k] = 2;
				// cerr << g[i][j][k] << ' ';
			}
			// cerr << '\n';
		}
		// cerr << '\n';
	}
	// return;

	bool good = true;
	for(int i=0;i<d;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(vis[i][j][k])continue;
				if(g[i][j][k] == 0)continue;
				vector<vector<int>> q = {{i,j,k}};
				vis[i][j][k] = 1;
				ll sum = 0;
				for(int qh=0;qh<q.size();qh++){
					vector<int> c = q[qh];
					if((c[0] + c[1] + c[2])%2 == 0){
						// if(g[c[0]][c[1]][c[2]] == 2)sum--;
						sum += g[c[0]][c[1]][c[2]];
					}else{
						// if(g[c[0]][c[1]][c[2]] == 2)sum++;
						sum -= g[c[0]][c[1]][c[2]];
					}



					if(c[0] + 1 < d && !vis[c[0] + 1][c[1]][c[2]] && g[c[0] + 1][c[1]][c[2]]){
						vis[c[0] + 1][c[1]][c[2]] = 1;
						q.push_back({c[0] + 1,c[1] , c[2]});
					}

					if(c[0] - 1 >=0 && !vis[c[0] - 1][c[1]][c[2]] && g[c[0] - 1][c[1]][c[2]]){
						vis[c[0] - 1][c[1]][c[2]] = 1;
						q.push_back({c[0] - 1,c[1] , c[2]});
					}

					//////////////

					if(c[1] + 1 < n && !vis[c[0]][c[1] + 1][c[2]] && g[c[0]][c[1] + 1][c[2]]){
						vis[c[0]][c[1] + 1][c[2]] = 1;
						q.push_back({c[0],c[1] + 1 , c[2]});
					}

					if(c[1] - 1 >= 0 && !vis[c[0]][c[1] - 1][c[2]] && g[c[0]][c[1] - 1][c[2]]){
						vis[c[0]][c[1] - 1][c[2]] = 1;
						q.push_back({c[0],c[1] - 1 , c[2]});
					}

					//////////////

					if(c[2] + 1 < m && !vis[c[0]][c[1]][c[2] + 1] && g[c[0]][c[1]][c[2] + 1]){
						vis[c[0]][c[1]][c[2] + 1] = 1;
						q.push_back({c[0],c[1] , c[2] + 1});
					}

					if(c[2] - 1 >=0 && !vis[c[0]][c[1]][c[2] - 1] && g[c[0]][c[1]][c[2] - 1]){
						vis[c[0]][c[1]][c[2] - 1] = 1;
						q.push_back({c[0],c[1] , c[2] - 1});
					}

				}

				// cerr << i << ' ' << j << ' ' << k << ' ' << sum << '\n';
				if(sum != 0){
					good = false;
				}
			}
		}
	}

	cout << (good ? "YES\n" : "NO\n");
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