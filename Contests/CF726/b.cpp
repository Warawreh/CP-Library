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
	int t;
	cin>>t;
	while(t--){
		ll n,m,a,b;
		cin>>n>>m>>a>>b;
		ll ans = -1;
		vector<ll> xx = {1,n};
		vector<ll> yy = {1,m};
		pair<int,int> ata,atb;
		for(ll x1 : xx){
			for(ll y1 : yy){
				for(ll x2 : xx){
					for(ll y2 : yy){
						ll dist = abs(a - x1) + (b - y1) + abs(y1 - y2) + abs(x1 - x2) + abs(x2 - a) + abs(y2 - b);
						if(dist > ans){
							ata = {x1,y1};
							atb = {x2,y2};
						}
						ans = max(ans , dist);
					}
				}
			}
		}
		cout << ata.first << ' ' << ata.second << ' ' << atb.first << ' ' << atb.second << '\n';
	}
}