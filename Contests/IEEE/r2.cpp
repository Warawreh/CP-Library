#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> g;
string dir = "><^v";
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector< vector<ll> > vis,onCycle;
int toD;
pair<int,int> head;

void dfs(int r,int c,int dist){
    if( vis[r][c] != -1 ){
        toD = dist;
        head = {r,c};
        return ;
    }
    vis[r][c] = dist;
    // cerr << r << ' ' << c << ' ' << dist << '\n';

    for(int i=0;i<4;i++){
        if(g[r][c] != dir[i])continue;
        int nr = r + dx[i];
        int nc = c + dy[i];
        dfs(nr , nc , dist + 1);
    }
}

void dfs2(int r,int c){
    if( onCycle[r][c] != -1 ){
        return ;
    }
    onCycle[r][c] = 1;

    for(int i=0;i<4;i++){
        if(g[r][c] != dir[i])continue;
        int nr = r + dx[i];
        int nc = c + dy[i];
        dfs2(nr , nc);
    }
}

void solve(){
	int d,n;
	cin>>n;

	
	g.clear();
	g.resize(n);
    vis = onCycle = vector< vector<ll> > ( n , vector<ll> ( n , -1 ) );
	vector<vector<vector<pair<int,int>>>> to(n,vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(30)));

    for(int i=0;i<n;i++){
		cin>>g[i];
		for(int j=0;j<n;j++){
			int nr,nc;
			for(int x=0;x<4;x++){
				if(g[i][j] != dir[x])continue;
				nr = i + dx[x];
				nc = j + dy[x];
			}
			to[i][j][0] = {nr,nc};
		}
	}


    dfs( 0 , 0 , 0 );
    dfs2( head.first , head.second);

	for(int k=1;k<30;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				pair<int,int> c = to[i][j][k-1];
				to[i][j][k] = to[c.first][c.second][k-1];
			}
		}
	}

	function<pair<int,int>(int)> reach = [&](int move){
		int r=0,c=0;
		for(int k=29;k>=0;k--){
			if((move >> k) & 1){
				pair<int,int> cr = to[r][c][k];
				r = cr.first;
				c = cr.second;
			}
		}
		return make_pair(r,c);
	};

	ll ans = 1e18;
	cin>>d;
	for(int i=0;i<d;i++){
		int r,c;
		cin>>r>>c;
		if(onCycle[r][c] != -1){
			for(ll j=0;j<100;j++){
				if(reach(i + d * j) == make_pair(r,c)){
					ans = min(ans , i + d * j);
					break;
				}
			}
		}else{
			if(vis[r][c] != -1){
				if(vis[r][c] % d == i){
					ans = min(ans , vis[r][c]);
				}
			}
		}
	}

	if(ans >= 1e18)cout << "never\n";
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