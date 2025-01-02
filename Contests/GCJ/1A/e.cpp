#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int,int> dir[] = {{-1,-1} , {0,-1} , {1,-1} , {-1,0} , {0,0} , {1,0} , {-1,1} , {0,1} , {1,1}};
vector<vector<vector<pair<int,int>>>> to;
int n,m,q;

pair<int,int> dist(int x,int y,int mm){
	for(int k=31;k>=0;k--){
		if((mm >> k) & 1){
			if(x < 0 || x >= n || y < 0 || y >= m)return {x,y};
			pair<int,int> nxt = to[k][x][y];
			x = nxt.first;
			y = nxt.second;
		}
	}
	return {x,y};
}

int main(){
	fast
	cin>>n>>m>>q;
	vector<vector<int>> g(n,vector<int>(m));
	to = vector<vector<vector<pair<int,int>>>>(32,vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(m)));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			to[0][i][j] = {i + dir[g[i][j]].second , j + dir[g[i][j]].first};
		}
	for(int k=1;k<32;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int nx = to[k-1][i][j].first;
				int ny = to[k-1][i][j].second;
				if(nx < n && nx >= 0 && ny < m && ny >= 0){
					to[k][i][j] = to[k-1][nx][ny];
				}else{
					to[k][i][j] = {-1,-1};
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		int sx,sy,ex,ey,k;
		cin>>sx>>sy>>ex>>ey>>k;

		sx--;sy--;ex--;ey--;

		bool can = false;
		for(int x=sx-1;x<=sx+1;x++){
			for(int y=sy-1;y<=sy+1;y++){
				if(dist(x,y,k - 1) == make_pair(ex,ey)){
					can = true;
					break;
				}
			}
		}
		pair<int,int> r = dist(sx,sy,k-1);
		if(abs(r.first - ex) <= 1 && abs(r.second - ey) <= 1)can = true;
		if(can)cout << "Yes\n";
		else cout << "No\n";
	}
}