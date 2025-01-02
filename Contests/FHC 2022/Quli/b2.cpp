#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void solve(){
	int n,m;
	cin>>n>>m;
	int tc = 0;
	vector<string> s(n);


	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++)tc += (s[i][j] == '^');
	}
	
	if(tc == 0){
		cout << "Possible\n";
		for(int i=0;i<n;i++)cout << s[i] << '\n';
		return;
	}

	vector<vector<bool>> blocked(n,vector<bool>(m,0));
	vector<pair<int,int>> q;
	bool can = true;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j] == '#')continue;

			int friends = 0;
			for(int x=0;x<4;x++){
				int nr = dx[x] + i;
				int nc = dy[x] + j;

				if(nr == n || nr < 0 || nc < 0 || nc == m || s[nr][nc] == '#')continue;

				friends++;
			}
			if(friends <= 1){
				if(s[i][j] == '^'){
					cout << "Impossible\n";
					return;
				}

				q.push_back({i,j});
				blocked[i][j] = 1;
			}
		}
	}

	int qh = 0;

	for(qh=0;qh<q.size();qh++){
		int r = q[qh].first;
		int c = q[qh].second;

		for(int x=0;x<4;x++){
			int nr = dx[x] + r;
			int nc = dy[x] + c;

			if(nr == n || nr < 0 || nc < 0 || nc == m || blocked[nr][nc] || s[nr][nc] == '#')continue;

			int friends = 0;
			for(int x=0;x<4;x++){
				int nnr = dx[x] + nr;
				int nnc = dy[x] + nc;

				if(nnr == n || nnr < 0 || nnc < 0 || nnc == m || blocked[nnr][nnc] || s[nnr][nnc] == '#')continue;
				friends++;
			}

			if(friends <= 1){
				if(s[nr][nc] == '^'){
					cout << "Impossible\n";
					return;
				}

				q.push_back({nr,nc});
				blocked[nr][nc] = 1;
			}
		}
	}

	cout << "Possible\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j] == '#')cout << s[i][j];
			else{
				if(blocked[i][j])cout << '.';
				else cout << '^';
			}
		}
		cout << '\n';
	}


}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}