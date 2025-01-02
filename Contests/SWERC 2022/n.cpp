#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1505;
ll ans;
ll rows[nax],cols[nax];
int n;

void solve(vector<pair<int,pair<int,int>>> p){
	
	for(int l=0;l<n*n;l++){
		int i = p[l].second.first;
		int j = p[l].second.second;

		ans += (n - 1 - rows[i]) * cols[j] + rows[i]  * (n - 1 - cols[j]);
		rows[i]++;
		cols[j]++;
	}
}

int main(){
	fast
	cin>>n;
	vector<pair<int,pair<int,int>>> p;
	vector<vector<int>> g(n,vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			g[i][j] = x;
			p.push_back({x,{i,j}});

		}
		// cout << rows[i].to_string().substr(nax-n) << '\n';
	}
	sort(all(p));

	solve(p);

	// reverse(all(p));
	// for(int i=0;i<n;i++)
	// 	for(int j=0;j<n;j++){
	// 		rows[i][j] = 1;
	// 		cols[j][i] = 1;
	// 	}
	// solve(p);

	cout << ans/2 << '\n';

}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/