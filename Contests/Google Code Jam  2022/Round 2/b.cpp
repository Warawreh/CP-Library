#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<bool>> g,g2;
int r;

void set_pixel_to_black(int x,int y,vector<vector<bool>>&g){
	x += r;
	y += r;
	g[x][y] = 1;
}

void draw_circle_perimeter(ll r){
	for(ll x=-r;x<=r;x++){
		ll y = ceil(sqrt(r * r - x* x) - 0.5);
		set_pixel_to_black(x,y,g);
		set_pixel_to_black(x,-y,g);
		set_pixel_to_black(y,x,g);
		set_pixel_to_black(-y,x,g);
	}
}

void draw_circle_filled(ll r){
	for(ll x = -r;x<=r;x++){
		for(ll y=-r;y<=r;y++){
			if(ceil(sqrt(x*x + y*y) - 0.5) <= r){
				set_pixel_to_black(x, y,g2);
				// cerr << x << ' ' << y << ' ' << ceil(sqrt(x*x + y*y) - 0.5) << '\n';
			}
		}
	}
}

void draw_circle_filled_wrong(ll r){
	for(int R=0;R<=r;R++){
		draw_circle_perimeter(R);
	}
}

void solve(){
	// cin>>r;
	g.clear();
	g2.clear();
	g = g2 = vector<vector<bool>>(r+r+1,vector<bool>(r+r+1,0));

	draw_circle_filled(r);
	draw_circle_filled_wrong(r);

	for(int i=0;i<r+r+1;i++){
		for(int j=0;j<r+r+1;j++){
			if(g[i][j])
				cerr << g[i][j];
			else if(g2[i][j])cerr << 2;
			else cerr << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';

	int ans = 0;
	for(int i=0;i<=r+r;i++){
		for(int j=0;j<=r+r;j++)
			ans += g[i][j] ^ g2[i][j];
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		r = T;
		solve();
	}
}