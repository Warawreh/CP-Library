#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
const int nax = 1e5 + 10;
int dp[nax][6][2];
vector<vector<pair<int,int>>> g;

int can(int u,int p,int dir){

	int ord = 0;
	for(auto &[v,d] : g[u]){
		if(v == p)break;
		if(d == dir)ord++;
	}	
	ord = min(ord , 1);	

	int &ret = dp[u][dir][ord];
	if(ret != -1)return ret;
	ret = 1;
	int all = 0;
	for(auto &[v,d] : g[u]){
		if(v == p)continue;
		if((all >> d) & 1)return ret = 0;
		if(d == (dir ^ 1))return ret = 0;
		all |= (1 << d);
		ret &= can(v , u, d);
		if(!ret)return ret;
	}
	return ret;
}

void solve(){
	cin >> n ;

	g.clear();
	g.resize(n);

	for(int i=0;i<n-1;i++){
		int u,v;
		char c;
		cin>>u>>v>>c;
		int x = 0;
		if(c == 'U')x = 0;
		if(c == 'D')x = 1;
		if(c == 'L')x = 2;
		if(c == 'R')x = 3;

		u--;v--;

		g[u].push_back({v,x});
		g[v].push_back({u,x});

	}

	for(int i=0;i<n;i++){
		assert(g[i].size() <= 4);
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++)
			for(int l=0;l<2;l++)
				dp[i][j][l] = -1;

	for(int i=0;i<n;i++){
		if(can(i , -1 , 5)){
			cout << i + 1 << ' ';
		}
	}
	cout << '\n';

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