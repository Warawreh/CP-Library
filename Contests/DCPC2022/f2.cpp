#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> g;
const ll oo = 1e18;
int n,m;

void solve(){
	cin>>n>>m;

	g.clear();
	g = vector<vector<int>>(n,vector<int>(m));

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];

	vector<vector<ll>> bst(m , vector<ll>(m,0));
	ll ans = 0;

	for(int i=0;i<n;i++){
		vector<vector<ll>> nxt(m , vector<ll>(m,0));
		for(int l=0;l<m;l++){
			ll sum=0,best =0;
			for(int r=l;r<m;r++){
				sum += g[i][r];

				for(int msk=0;msk<(1 << m);msk++){
					bool good = true;
					int fr=-1;
					ll all = 0;
					for(int j=0;j<m;j++){
						if((msk >> j & 1)){
							if(fr == -1)fr = j;
						}else{
							if(fr != -1){
								if(fr <= r && j-1 >= l){
									all += bst[fr][j-1];
								}else good = false;
							}
							fr = -1;
						}
					}
					if(fr != -1){
						if(fr <= r && m-1 >= l){
							all += bst[fr][m-1];
						}
					}

					if(good)best = max(best , all);

				}

				ll val = sum + best;
				nxt[l][r] = max(nxt[l][r] , val);
				ans = max(ans , nxt[l][r]);
			}
		}
		bst = nxt;
	}

	cout << ans << '\n';

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