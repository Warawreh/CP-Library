#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	k--;
	vector<string> g(n);
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	vector<vector<int>> carDown(m,vector<int>(n));
	vector<vector<int>> carUP(m,vector<int>(n));
	for(int j=0;j<m;j++){
		int cnt = 0;
		for(int i=0;i<k;i++){
			cnt += g[i][j] == 'X';
		}
		for(int t=0;t<n;t++){
			if(k + t >= n)break;
			cnt += g[k + t][j] == 'X';
			if(cnt > k){
				carUP[j][t] = 1;
				continue;
			}
			carUP[j][t] = g[k + t][j] == 'X';
		}
		for(int t=n-k;t<n;t++){
			if(cnt > k)
				carUP[j][t] = 1;
			else{
				carUP[j][t] = 0;
			}
		}
	}

	for(int j=0;j<m;j++){
		int cnt = 0;
		for(int i=n-1;i>k;i--){
			cnt += g[i][j] == 'X';
		}
		for(int t=0;t<n;t++){
			if(k - t < 0)break;
			cnt += g[k - t][j] == 'X';
			if(cnt > n-k-1){
				carDown[j][t] = 1;
				continue;
			}
			carDown[j][t] = g[k - t][j] == 'X';
		}
		for(int t=k+1;t<n;t++){
			if(cnt > n-k-1)
				carDown[j][t] = 1;
			else{
				carDown[j][t] = 0;
			}
		}
	}

	ll ans = 1e18;
	for(int t=0;t<n;t++){
		ll tot = 0;
		for(int j=0;j<m;j++){
			tot += carUP[j][t];
		}
		ll tot2 = 0;
		for(int j=0;j<m;j++){
			tot2 += carDown[j][t];
		}
		// cerr << t << ' ' << tot << ' ' << tot2 << '\n';
		ans = min(ans , t + tot);
		ans = min(ans , t + tot2);
	}
	// assert(ans >= 0 && ans <= m);
	cout << ans << '\n';
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