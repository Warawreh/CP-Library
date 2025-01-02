#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k;
vector<vector<int>> trans1,trans2;

pair<int,int> valToPos(){
	int x=0,y=0;
	int dx=0,dy=1;
	int cur = n-1;
	int timer = 0;
	int at = 1;
	while(at < n*n){
		// cerr << val << ' ' << x << ' ' << y << ' ' << cur << '\n';
		trans1.push_back({at,x,y,dx,dy});

		at += cur;

		x += dx * cur;
		y += dy * cur;

		if(dx){
			dy = -1 * dx;
			dx = 0;
		}else if(dy){
			dx = dy;
			dy = 0;
		}

		timer++;
		if(timer == 3){
			timer = 1;
			cur--;
		}
	}
	return {x,y};
}

int posToVal(int i,int j){
	int x=0,y=0;
	int dx=0,dy=1;
	int cur = n-1;
	int timer = 0;
	int at = 1;
	while(x != n/2 || y != n/2){
		// cerr << val << ' ' << x << ' ' << y << ' ' << cur << '\n';

		int nx = x + dx * cur;
		int ny = y + dy * cur;

		if(nx == x && nx == i){
			int diff = abs(y - j);
			return at + diff;
		}else if(ny == y && ny == j){
			int diff = abs(x - i);
			return at + diff;
		}


		x += dx * cur;
		y += dy * cur;

		at += cur;

		if(dx){
			dy = -1 * dx;
			dx = 0;
		}else if(dy){
			dx = dy;
			dy = 0;
		}

		timer++;
		if(timer == 3){
			timer = 1;
			cur--;
		}
	}

	return n*n;
}

void solve(){
	cin>>n>>k;
	trans1.clear();
	valToPos();

	for(int cut=1;cut<=n-1;cut++){
		int need = k - cut + 1;
		if(need <= 0)break;
		vector<int> tmp = {need,(int)1e9,(int)1e9,(int)1e9,(int)1e9};
		int atp = upper_bound(all(trans1),tmp) - trans1.begin() - 1;
		// cerr << atp << '\n';
		int extra = need - trans1[atp][0];
		pair<int,int> res = {trans1[atp][1] + extra * trans1[atp][3] , trans1[atp][2] + extra * trans1[atp][4] };
		int x = res.first;
		int y = res.second;
		if(abs(x - n/2) + abs(y - n/2) == cut){
			vector<int> points = {need };

			// cerr << x << ' ' << y << '\n';
			int dx = 1,dy = 1;
			if(x > n/2)dx = -1;
			if(y > n/2)dy = -1;
			while(x != n/2 || y != n/2){
				int nx = x + dx;
				int ny = y + dy;

				if(x != n/2){
					int nVal = posToVal(nx,y);
					if(nVal > points.back()){
						points.push_back(nVal);
						x = nx;
						continue;
					}

				}
				assert(y != n/2);
				int nVal = posToVal(x,ny);
				if(nVal > points.back()){
					points.push_back(nVal);
					y = ny;
					continue;
				}
				assert(0);
			}


			if(y < n/2){
				for(;y<n/2;){
					y++;
					points.push_back(posToVal(x,y));
				}
			}else if(y > n/2){
				for(;y>n/2;){
					y--;
					points.push_back(posToVal(x,y));
				}
			}
			vector<pair<int,int>> ans;
			for(int i=1;i<points.size();i++){
				assert(points[i] > points[i-1]);
				if(points[i] - 1 != points[i-1]){
					ans.push_back({points[i-1] , points[i]});
				}
			}
			cout << ans.size() << '\n';
			for(auto a : ans)
				cout << a.first << ' ' << a.second << '\n';
			return;
		}
	}

	cout << "IMPOSSIBLE\n";
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