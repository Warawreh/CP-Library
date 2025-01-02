#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int r,c,n,q;

vector<vector<int>> g,sum;

void build(){
	for(int i=0;i<g.size();i++){
		for(int j=0;j<g[i].size();j++){
			sum[i][j] = g[i][j] + (i ? sum[i-1][j] : 0) + (j ? sum[i][j-1] : 0) - (i && j ? sum[i-1][j-1] : 0);
		}
	}
}


int get(int r1,int c1,int r2,int c2){
	return sum[r2][c2] - (r1 ? sum[r1-1][c2] : 0) - (c1 ? sum[r2][c1-1] : 0) + (c1 && r1 ? sum[r1-1][c1-1] : 0);
}


void solve(){
	g = sum = vector<vector<int>> (r + c + 1 , vector<int> (max(r,c) * 2,0));
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x+y][c-1+x-y] = 1;
	}
	// for(int i=0;i<g.size();i++){
	// 	for(int j=0;j<g[i].size();j++){
	// 		cout << g[i][j];
	// 	}
	// 	cout << '\n';
	// }
	// return;
	build();
	for(int it=0;it<q;it++){
		int best = -1;
		pair<int,int> p = {-1,-1};
		int m;
		cin>>m;
		for(int R=0;R<r;R++){
			int i = R;
			int j = c - 1 + R;
			for(int cnt=0;cnt<c;cnt++){
				int a = i;
				int b = j + 1 - c;
				int x = (a + b)/2;
				if((a + b) % 2)continue;
				if(x < 0 || (a - x) < 0)continue;
				int have = get(max(0,i-m) , max(0,j-m) , min(c+r-1,i+m) , min(r+c-1,j+m));
				pair<int,int> cp = {a - x , x };
				if(have > best){
					best = have;
					p = cp;
					// cerr << i << ' ' << j << '\n';
				}else if(have == best)p = min(p , cp);
				i++;
				j--;
				if(j < 0 || i >= r + c){
					// cerr << "WTF\n";
					break;
				}
			}
		}
		// cerr << '\n';
		cout << best << " (" << p.second+1 << ',' << p.first + 1 << ')' << '\n';
	}
}

int main(){
	fast
	for(int Test=1;;Test++){
		cin>>r>>c>>n>>q;
		if(!r && !c && !n && !q)break;
		cout << "Case " << Test << ":\n";
		solve();
	}
}