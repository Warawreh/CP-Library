#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int e,w;
	cin>>e>>w;
	vector<vector<int>> g(e,vector<int> (w));
	for(int i=0;i<e;i++){
		for(int j=0;j<w;j++){
			cin>>g[i][j];
		}
	}
	// g.push_back(vector<int>(w,0));
	// e++;

	vector<vector<int>> hv;
	hv.push_back(g[0]);

	ll ans = 0;
	for(int i=0;i<w;i++)ans += hv[0][i] + g[e-1][i];

	for(int i=1;i<e;i++){
		vector<int> nxt(w);

		for(int j=0;j<w;j++){
			if(g[i][j] >= g[i-1][j]){
				nxt[j] = g[i][j] - g[i-1][j];
				ans += g[i][j] - g[i-1][j];
			}else{
				int rem = g[i-1][j] - g[i][j];
				ans += rem;
				int len = 0;
				for(int k=hv.size()-1;k>=0;k--){
					int sum = 0;
					for(int x=0;x<w;x++)sum += hv[k][x];
					if(!sum)continue;

					len++;
					int r = min(rem, hv[k][j]);


					hv[k][j] -= r;
					rem -= r;
					ans += (len - 1) * 2 * r;
					// cerr << len << ' ' << r << '\n';
				}
				// cerr << ans << '\n';
				nxt[j] = 0;
			}
		}
		
		
		hv.push_back(nxt);
	}
	
	cout << ans  << '\n';
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