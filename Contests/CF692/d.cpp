#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int nax = 1111;
 
string g[nax];
int n,m;
int cost[nax][nax][2];
pair<int,int> fr[nax][nax][2];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
string dir = "DURL";
 
bool good(int r,int c,int t){
	if(r == n || c == m || r < 0 || c < 0 || g[r][c] == '#' || cost[r][c][t] != -1)
		return 0;
	return 1;
}
 
bool border(int r,int c){
	if(r == 0 || c == 0 || r == n-1 || c == m-1)return true;
	return false;
}
 
void bfs(char c,int t){
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j] == c){
				q.push({i,j});
				cost[i][j][t] = 0;
			}
	while(q.size()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(!good(nr,nc,t))continue;
			fr[nr][nc][t] = {r,c};
			cost[nr][nc][t] = cost[r][c][t] + 1;
			q.push({nr,nc});
		}
	}
}
 
int main(){
	fast
	memset(cost,-1,sizeof(cost));
	memset(fr,-1,sizeof(fr));
	cin>>n>>m;
	if(n == 1 && m == 1){
		cout << "YES\n0\n";
		return 0;
	}
	for(int i=0;i<n;i++)cin>>g[i];
	bfs('A',0);
	bfs('M',1);
	// cerr << cost[2][3][0] << ' ' << cost[2][3][1] << '\n';
	pair<int,int> st = {-1,-1};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(cost[i][j][1] == -1)cost[i][j][1] = 1e9;
			if(cost[i][j][0] == -1)cost[i][j][1] = 1e9;
		}
	}
	for(int i=0;i<n;i++){
		if(cost[i][0][0] < cost[i][0][1] && cost[i][0][0] != -1){
			st = {i,0};
		}
	}
	for(int i=0;i<n;i++){
		if(cost[i][m-1][0] < cost[i][m-1][1] && cost[i][m-1][0] != -1){
			st = {i,m-1};
		}
	}
	for(int i=0;i<m;i++){
		if(cost[0][i][0] < cost[0][i][1] && cost[0][i][0] != -1){
			st = {0,i};
		}
	}
	for(int i=0;i<n;i++){
		if(cost[n-1][i][0] < cost[n-1][i][1] && cost[n-1][i][0] != -1){
			st = {n-1,i};
		}
	}
	if(st.first == -1){
		cout << "NO\n";
		return 0;
	}
	string ans;
	while(st.first != -1){
		int nr = st.first;
		int nc = st.second;
		int r = fr[nr][nc][0].first;
		int c = fr[nr][nc][0].second;
		for(int i=0;i<4;i++){
			if(r + dr[i] == nr && c + dc[i] == nc)ans += dir[i];
		}
		if(cost[nr][nc][0] >= cost[nr][nc][1] && border(nr,nc) == 0){
			cout << "NO\n";
			return 0;
		}
		st = {r,c};
	}
	cout << "YES\n";
	reverse(ans.begin(),ans.end());
	cout << ans.size() << endl;
	cout << ans << endl;
}