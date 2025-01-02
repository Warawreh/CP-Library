#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> DIR = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
	fast
	int n,m;
	cin>>n>>m;
	vector<string> s(n);
	vector<vector<pair<int,int>>> t(26);
	pair<int,int> beg,fin;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			if(s[i][j] == 'S')beg = {i,j};
			else if(s[i][j] == 'G')fin = {i,j};
			else if(s[i][j] >= 'a' && s[i][j] <= 'z')t[s[i][j] - 'a'].push_back({i,j});
		}
	}

	vector<vector<int>> d(n,vector<int>(m,{-1}));
	queue<pair<int,int>> q;
	d[beg.first][beg.second] = 0;
	q.push(beg);
	while(q.size()){
		pair<int,int> u = q.front();
		q.pop();
		if(s[u.first][u.second] >= 'a' && s[u.first][u.second] <= 'z'){
			int W = s[u.first][u.second] - 'a';
			for(pair<int,int> p : t[W]){
				if(d[p.first][p.second] == -1){
					d[p.first][p.second] = d[u.first][u.second] + 1;
					q.push(p);
				}
			}
			t[W].clear();
		}
		for(vector<int> dir : DIR){
			int r = u.first + dir[0];
			int c = u.second - dir[1];
			if(r < 0 || r == n || c < 0 || c == m || s[r][c] == '#' || d[r][c] != -1)continue;
			d[r][c] = 1 + d[u.first][u.second];
			q.push({r,c});
		}
	}
	cout << d[fin.first][fin.second] << '\n';
}