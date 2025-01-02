#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n;
	cin>>n;
	vector<int> a(3),b(3);
	vector<vector<int>> wt = {
		{0,1,0},
		{0,0,1},
		{1,0,0}
	};
	for(int i=0;i<3;i++)cin>>a[i];
	for(int i=0;i<3;i++)cin>>b[i];
	vector<vector<int>> match;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)match.push_back({i,j});
	sort(all(match));
	int mx = 0,mn = n;
	do{
		vector<vector<int>> tmp = {a,b};
		int wins = 0;
		for(int i=0;i<match.size();i++){
			vector<int> who = match[i];
			int &a = tmp[0][who[0]];
			int &b = tmp[1][who[1]];
			int m = min(a , b);
			a -= m;
			b -= m;
			wins += wt[who[0]][who[1]] * m;
		}

		mn = min(mn , wins);
		mx = max(mx , wins);
	}while(next_permutation(all(match)));
	cout << mn << ' ' << mx << '\n';
}