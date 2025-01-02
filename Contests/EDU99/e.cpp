#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<ll,ll> dim[4][4] = {
	{{0,0} , {1,0} , {0,1} , {1,1}},
	{{0,0} , {1,0} , {0,-1} , {1,-1}},
	{{0,0} , {-1,0} , {0,1} , {-1,1}},
	{{0,0} , {-1,0} , {0,-1} , {-1,-1}}
};

vector<pair<ll,ll>> p;

ll D(pair<ll,ll> a,pair<ll,ll> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

ll dist(vector<pair<ll,ll>> d){
	sort(all(d));
	ll res = 1e18;
	do{
		ll cur = 0;
		for(int i=0;i<d.size();i++)
			cur += D(d[i] , p[i]);
		res = min(res , cur);
	}while(next_permutation(all(d)));

	return res;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		p = vector<pair<ll,ll>>(4);
		for(int i=0;i<4;i++){
			cin>>p[i].first>>p[i].second;
		}
		sort(all(p));
		ll ans = 1e18;

		for(int w = 0;w<4;w++){
				ll cx=p[w].first,cy=p[2].second;

				ll lo=0,hi=1e9/2;
				// cerr << cx << ' ' << cy << '\n';	
				for(int it=0;it<60;it++){
					// cerr << it << '\n';
					ll md1 = lo + (hi - lo)/3;
					ll md2 = hi - (hi - lo)/3;
					ll cst1=1e18,cst2=1e18;
					{
						ll len = md1;
						for(int j=0;j<4;j++){
							vector<pair<ll,ll>> d;
							for(int i=0;i<4;i++){
								d.push_back({cx + len * dim[j][i].first , cy + len * dim[j][i].second});
							}
							cst1 = min(cst1,dist(d));
						}
					}

					{
						ll len = md2;
						for(int j=0;j<4;j++){
							vector<pair<ll,ll>> d;
							for(int i=0;i<4;i++){
								d.push_back({cx + len * dim[j][i].first , cy + len * dim[j][i].second});
							}
							cst2 = min(cst2,dist(d));
						}
					}

					ans = min(ans , min(cst1,cst2));
					if(cst1 <= cst2)hi = md2 - 1;
					else lo = md1 + 1;
			}
		}
		cout << ans << '\n';
	}
}