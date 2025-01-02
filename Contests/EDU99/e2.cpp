#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int,int> dim[] = {{1,1} , {1,-1} , {-1,1} , {-1,-1}};

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
		
		ll ans = 1e18;
		ll lo=0,hi=1e10;
		for(int w = 0;w<4;w++){
			for(int W=0;W<4;W++){
				ll cx=p[w].first,cy=p[W].second;
				for(int it=0;it<60;it++){
					ll md1 = lo + (hi - lo)/3;
					ll md2 = hi - (hi - lo)/3;
					ll cst1=0,cst2=0;
					if(md1%2 == 0){
						ll len = md1/2;
						vector<pair<ll,ll>> d;
						for(int i=0;i<4;i++){
							d.push_back({cx + len * dim[i].first , cy + len * dim[i].second});
						}
						cst1 = dist(d);
					}else{
						cst1 = 1e18;
						ld len = md1/2.0;
						for(int i=0;i<4;i++){
							ld x = cx + 0.5 * dim[i].first;
							ld y = cy + 0.5 * dim[i].second;
							// cerr << x << ' ' << y << '\n';
							vector<pair<ll,ll>> d;
							for(int i=0;i<4;i++){
								d.push_back({x + len * dim[i].first , y + len * dim[i].second});
							}
							cst1 = min(cst1,dist(d));
						}
					}
					// cout << cst1 << '\n';
					// break;

					if(md2%2==0){
						ll len = md2/2;
						vector<pair<ll,ll>> d;
						for(int i=0;i<4;i++){
							d.push_back({cx + len * dim[i].first , cy + len * dim[i].second});
						}
						cst2 = dist(d);
					}else{
						cst2 = 1e18;
						ld len = md2/2.0;
						for(int i=0;i<4;i++){
							ld x = cx + 0.5 * dim[i].first;
							ld y = cy + 0.5 * dim[i].second;
							vector<pair<ll,ll>> d;
							for(int i=0;i<4;i++){
								d.push_back({x + len * dim[i].first , y + len * dim[i].second});
							}
							cst2 = min(cst2,dist(d));
						}
					}
					ans = min(ans , min(cst1,cst2));
					if(cst1 <= cst2)hi = md2;
					else lo = md1;
				}
			}

		}
		cout << ans << '\n';
	}
}