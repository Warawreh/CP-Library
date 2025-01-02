#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	cin>>n;
	vector<vector<bool>> closed(22,vector<bool>(361));
	vector<vector<bool>> wall(22,vector<bool>(361));
	for(int i=0;i<n;i++){
		char t;
		cin>>t;
		if(t == 'C'){
			int r,t1,t2;
			cin>>r>>t1>>t2;
			r--;
			int dif = (t2 - t1 + 360)%360;
			for(int j=0;j<dif;j++)
				closed[r][(t1 + j)%360] = 1;
		}else{
			int r1,r2,t1;
			cin>>r1>>r2>>t1;
			r1--;r2--;
			for(int j=r1;j<=r2;j++){
				wall[j][t1] = 1;
			}
		}
	}
	vector<bool> good(360,1);
	for(int l=0;l<=21;l++){
		vector<bool> nxt(360,0);
		for(int st=0;st<360;st++){
			if(!good[st])continue;
			{//clock wise
				for(int turn=0;turn<360;turn++){
					int at = (st + turn) % 360;
					if(!closed[l][at])nxt[at] = 1;
					if(wall[l][(at+1)%360] && wall[l+1][(at+1)%360]){
						break;
					}
				}
			}

			{//anti
				for(int turn=0;turn<360;turn++){
					int at = (st - turn + 360) % 360;
					if(!closed[l][at])nxt[at] = 1;
					if(wall[l][at] && wall[l+1][at]){
						break;
					}
				}
			}
		}
		good = nxt;

	}
	bool ans = false;
	for(int i=0;i<360;i++)ans |= good[i];
	cout << (ans ? "YES\n" : "NO\n");
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/