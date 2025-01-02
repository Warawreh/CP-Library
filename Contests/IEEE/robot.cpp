#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 404;
int dp[nax][nax][nax];
bool hv[nax][nax][nax];
vector<string> g;
int d;

string dir = "><^v";
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n;

void solve(){
	cin>>n;

	g.clear();
	g.resize(n);

	for(int i=0;i<n;i++){
		cin>>g[i];
	}

	cin>>d;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<d;k++){
				hv[i][j][k] = 0;
				dp[i][j][k] = -1;
			}


	int ans = 1e9;
	for(int i=0;i<d;i++){
		int r,c;
		cin>>r>>c;
		hv[r][c][i] = 1;
	}

	vector<vector<int>> q;
	q.push_back({0,0,0});
	dp[0][0][0] = 0;

	for(int qh=0;qh<q.size();qh++){
		int r = q[qh][0];
		int c = q[qh][1];
		int ds = q[qh][2];
		if(hv[r][c][ds]){
			ans = min(ans , dp[r][c][ds]);
			// cerr << r << ' ' << c << ' ' << dp[r][c][ds] << '\n';
		}

		// cerr << r << ' ' << c << ' ' << ds << ' ' << dp[r][c][ds] << '\n';

		for(int i=0;i<4;i++){
			if(g[r][c] != dir[i])continue;
			int nr = r + dx[i];
			int nc = c + dy[i];
			int ndist = (ds + 1)%d;
			if(nr < 0 || nr >= n || nc < 0 || nc >= n || dp[nr][nc][ndist] != -1)continue;
			dp[nr][nc][ndist] = dp[r][c][ds] + 1;
			q.push_back({nr , nc , ndist});
		}
	}


	if(ans == 1e9)cout << "never\n";
	else cout << ans << '\n';
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