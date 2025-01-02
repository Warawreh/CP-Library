#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e6 + 10;

int main(){
	fast
	vector<pair<int,int>> r(nax,make_pair(-1,-1));
	vector<vector<int>> rec(3,vector<int>(4));
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++)
			cin>>rec[i][j];
	}
	for(int i=1;i<3;i++){
		for(int x=rec[i][0];x<rec[i][2];x++){
			if(r[x] == make_pair(-1,-1))r[x] = {rec[i][1],rec[i][3]};
			if(r[x].second >= rec[i][1] && r[x].second <= rec[i][3] || r[x].first >= rec[i][1] && r[x].first <= rec[i][3]){
				r[x].first = min(r[x].first , rec[i][1]);
				r[x].second = max(r[x].second , rec[i][3]);
			}
			if(rec[i][1] <= rec[0][1] && rec[i][3] >= rec[0][3])r[x] = {rec[i][1],rec[i][3]};
		}
	}
	bool can = 0;
	for(int i=rec[0][0];i<rec[0][2];i++){
		// cerr << i << ' ' << r[i].first << ' ' << r[i].second << '\n';
		if(r[i].first <= rec[0][1] && r[i].second >= rec[0][3])continue;
		can = 1;
	}
	cout << (can ? "Yes\n" : "No\n");
}