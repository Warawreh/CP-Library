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
	vector<int> a(n);

	map<int , vector<pair<int,int>>> c;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int g;
		cin>>g;
		c[g].push_back({a[i] , i});
	}

	vector<vector<int>> g;
	vector<pair<int,int>> at(n);
	for(auto &it : c){
		sort(all(it.second));
		g.push_back({});
		for(int i=0;i<it.second.size();i++){
			int val = it.second[i].second;
			at[val] = {(int)g.size() - 1 , i};
			g.back().push_back(val);
			if(i && it.second[i-1].first == it.second[i].first){
				cout << -1 << '\n';
				return;
			}
		}
	}
	vector<int> point(g.size(),0);
	vector<int> ans(n,-1);
	int x=0;
	for(int i=0;i<n;i++){
		if(ans[i] != -1)continue;
		int id = at[i].first;
		int to = at[i].second;
		while(point[id] <= to){
			ans[g[id][point[id]]] = ++x;
			point[id]++;
		}
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << ' ';
	cout << '\n';

}

int main(){
    fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
