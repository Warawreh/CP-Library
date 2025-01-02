#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct pt{
	ld x,y;

	pt(){
		x = y = 0;
	}
	pt(ld X,ld Y){
		x = X;
		y = Y;
	}
	pt operator- ( pt p ){ return pt( x - p.x , y - p.y ); }
	bool operator< ( const pt &p ){
		if( x == p.x ){
			return ( y < p.y ); 
		}else return ( x < p.x ); 
	}

	bool operator> ( const pt &p ){
		if( x == p.x ){
			return ( y > p.y ); 
		}else return ( x > p.x ); 
	}
	void read(){
		cin>>x>>y;
	}
};
ld S( ld x ){ return x * x ; }
ld abs( pt p ){ return sqrt( S(p.x) + S(p.y) ) ; }
ld area( vector<pt> tri ){
	ld A = abs(tri[0]-tri[1]), B = abs(tri[1]-tri[2]) , C = abs(tri[2]-tri[0]) ;
	ld ang = S(B) + S(C) - S(A) ;
	ang = ang / ( 2 * B * C ) ; 
	ang = acos( ang ) ;
	ld a = B * C * sin(ang) / 2 ;
	return a;
	return 0;
}
map<vector<ld> , vector<int>> hv;
vector<vector<int>> g;
vector<int> vis;
vector<vector<pt>> tri;

vector<ld> bfs(int i){
	vector<ld> res(2,0);

	vis[i] = 0;
	vector<int> q = {i};
	for(int qh=0;qh<q.size();qh++){
		int u = q[qh];
		res[vis[u]] += area(tri[i]);

		for(int v : g[u]){
			if(vis[v] != -1)continue;
			vis[v] = !vis[u];
			q.push_back(v);
		}
	}

	return res;
}

int main(){
    fast
    int n;
    cin>>n;

    g.resize(n);
    vis = vector<int>(n,-1);

    ld tot = 0;
    tri = vector<vector<pt>>(n,vector<pt>(3));
    for(int i=0;i<n;i++){
    	for(int j=0;j<3;j++)
    		tri[i][j].read();

    	for(int j=0;j<3;j++){
    		pt a = tri[i][j];
    		pt b = tri[i][(j+1)%3];
    		if(a < b)swap(a,b);

    		vector<ld> v= {a.x , a.y , b.x,b.y};
    		hv[v].push_back(i);
    	}

    	tot += area(tri[i]);
    }
    vector<bool> good(n);
    for(int i=0;i<n;i++){
    	int cnt = 0;
    	for(int j=0;j<3;j++){
    		pt a = tri[i][j];
    		pt b = tri[i][(j+1)%3];
    		if(a < b)swap(a,b);
    		vector<ld> v= {a.x , a.y , b.x,b.y};
    		if(hv[v].size() == 2)cnt++;
    	}
    	if(cnt == 3)good[i] = 1;
    }

    for(int i=0;i<n;i++){
    	if(!good[i])continue;
    	for(int j=0;j<3;j++){
    		pt a = tri[i][j];
    		pt b = tri[i][(j+1)%3];
    		if(a < b)swap(a,b);
    		vector<ld> v= {a.x , a.y , b.x,b.y};
    		for(int id : hv[v]){
    			if(id == i)continue;
    			if(good[id]){
    				g[i].push_back(id);
    				g[id].push_back(i);
    			}
    		}
    	}
    }

    ld ans = 0;
    for(int i=0;i<n;i++){
    	if(!good[i] || vis[i] != -1 )continue;
    	vector<ld> res = bfs(i);
    	ans += max({res[0] , res[1]});
    }

    cout << setprecision(1) << fixed << tot - ans << '\n';
}
