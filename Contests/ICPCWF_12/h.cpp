#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ld S(ll a){return a*a;}

ld dist(vector<pair<ld,ld>> p){
	return sqrt(S(p[0].first - p.back().first) + S(p[0].second - p.back().second));
}
	
int main(){
	fast
	cout << setprecision(2) << fixed;
	int n,x,y;
	while(cin>>n>>x>>y){
		vector<pair<int,int>> p(n);
		ld ans = 1e18;
		for(int i=0;i<n;i++){
			cin>>p[i].first>>p[i].second;
		}
		p.push_back({x,y});
		for(int i=0;i<n;i++){
			ld cur = 0;
			for(int j=0;j<(n+1)/2;j++){
				vector<pair<ld,ld>> W(2);
				if(j == 0)W[0] = {x,y};
				else W[0] = p[(i + 2*(j-1))%n];
				W[1] = p[(i + 2*j)%n];
				cur += dist(W);
			}
			ans = min(ans , cur);
		}
		cout << ans << '\n';
	}
}