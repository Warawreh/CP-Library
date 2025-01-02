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
int n,m;
vector<vector<int>> g;
pair<int,int> s,e;

bool bfs(int b){
	vector<vector<bool>> vis(n,vector<bool>(m));
	vis[s.first][s.second] = true;
	queue<pair<int,int>> q;
	q.push(s);
	if(b & g[s.first][s.second])return false;

	while(q.size()){
		pair<int,int> u = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if(nx < 0 || ny < 0 || nx == n || ny == m || vis[nx][ny])continue;
			if((b & g[nx][ny]))continue;
			vis[nx][ny] = true;
			q.push({nx,ny});
		}
	}

	return vis[e.first][e.second];
}

void solve(){
	cin>>n>>m;
	g = vector<vector<int>>(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];
	cin>>s.first>>s.second>>e.first>>e.second;
	s.first--;
	s.second--;
	e.first--;
	e.second--;
	int ans = 0;
	int res = 0;
	for(int i=30;i>=0;i--){
		if(bfs(ans + (1<<i))){
			ans += (1<<i);
		}else{
			// cout << i << '\n';
			res += (1<<i);
		}
	}
	cout << res << '\n';
}

int main(){
	fast
	#ifndef LOCAL
		freopen("min.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)solve();
}