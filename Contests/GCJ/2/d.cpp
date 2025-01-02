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
	int r,c,f,s;
	cin>>r>>c>>f>>s;
	vector<string> a(r),b(r);
	for(int i=0;i<r;i++)
		cin>>a[i];
	for(int i=0;i<r;i++){
		cin>>b[i];
		for(int j=0;j<c;j++){
			if(a[i][j] == b[i][j]){
				a[i][j] = b[i][j] = '#';
			}
		}
	}

	// for(int i=0;i<r;i++)
	// 	cerr << a[i] << '\n';
	// cerr << '\n';
	int ans = 0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(a[i][j] == '#')continue;
			int f = 0;
			for(int x=0;x<4;x++){
				int nr = i + dx[x];
				int nc = j + dy[x];
				if(nr < 0 || nc < 0 || nr == r || nc == c || a[nr][nc] == '#')continue;
				if(a[nr][nc] == a[i][j])continue;
				f++;
			}
			if(f == 1){
				for(int x=0;x<4;x++){
					int nr = i + dx[x];
					int nc = j + dy[x];
					if(nr < 0 || nc < 0 || nr == r || nc == c || a[nr][nc] == '#')continue;
					if(a[nr][nc] == a[i][j])continue;
					a[nr][nc] = b[nr][nc] = '#';
				}
				a[i][j] = '#';
				ans++;
			}
		}

	// for(int i=0;i<r;i++)
	// 	cerr << a[i] << '\n';
	// cerr << '\n';

	int rest = 0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			rest += a[i][j] != '#';
	cout << ans + rest << '\n';	
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

/*
MGMG
***G

GMGM
***M


*/