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
	int n,m;
	cin>>n>>m;
	vector<vector<int>> c(n),s(m);
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		c[i] = {a,b};
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		s[i] = {a,b};
	}

	vector<vector<int>> s2 = s;
	int ans = 3e6;

	for(int it=0;it<2;it++){
		s = s2;
		sort(all(s));
		int mx = 0;
		int l=0;
		for(int i=m-2;i>=0;i--){
			s[i][1] = max(s[i+1][1] , s[i][1]);
		}
		vector<vector<pair<int,int>>> change(1e6 + 10);
		set<int> dist;
		vector<int> cst(n);

		for(int i=0;i<n;i++){
			int mx = 0;
			for(int j=0;j<m;j++){
				if(c[i][0] <= s[j][0]){
					int nc = 0;
					if(j + 1 < m){
						nc = max(0 , s[j+1][1] - c[i][1] + 1);
					}
					change[s[j][0] - c[i][0] + 1].push_back({i , nc});
					mx = max(mx , s[j][1] - c[i][1] + 1);
				}
			}
			cst[i] = mx;
			dist.insert(mx);
		}
		ans = *dist.rbegin();
		
		for(int r=0;r<=1e6+1;r++){
			for(pair<int,int> id : change[r]){
				int i = id.first;
				dist.erase(cst[i]);
				dist.insert(id.second);
				cst[i] = id.second;
			}
			// cerr << r << ' ' << *dist.rbegin() << '\n';
			ans = min(ans , r + *dist.rbegin());
		}

		for(int i=0;i<m;i++){
			swap(s2[i][0] , s2[i][1]);
		}
		for(int i=0;i<n;i++)
			swap(c[i][0] , c[i][1]);
	}

	cout << ans << '\n';
}