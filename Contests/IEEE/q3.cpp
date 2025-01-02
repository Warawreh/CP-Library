#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt = 0;
int a,b,k;

void prt(int i){
	if(i == 0){
		// cerr << a << ',';
		// cerr << "BAD " << a << ' ' << b << ' ' << b - a << ' ' << k  << '\n';
		cout << 0 << '\n';
	}else{
		cout << 1 << '\n';
		// cerr << a << ' ' << b << ' ' << k  << '\n';
	}
}

const ld eps = 1e-10;

ll S(ll a){return a * a;}

vector<ld> r = {1.6180339887487607953946155969759956860798,1.4142135623723012371327767411344211723190,1.3027756377299466257393273371789632619766,1.2360679774992961625981746642821690329583,1.1925824035675776433988726221713250197354,1.1622776601673339680852181654557853107690,1.1400549446399534235952605287778283127409,1.1231056256173178092751946399729945369472,1.1097722286484095041616398935602205710893,1.0990195135965919156009751311842137511121,1.0901699437473531201572840565461319783935};

void solve(){
	cin>>k>>a>>b;
	// k = 2;

	if(a == 0 && b == 0){
		prt(0);
		return;
	}
	if(a == 0 || b == 0 || abs(a - b) <= k){
		prt(1);
		return;
	}
	if(a > b)swap(a,b);
	ll ord = (b - a) / (k + 1);
	if((b - a) % (k + 1) != 0){
		prt(1);
		return;
	}

	ld val = 0;
	if(k < r.size()){
		val = r[k];
	}else{

		ll fr = 1;
		unordered_map<ll , bool> bad;
		ll add = (k + 1);
		vector<pair<ll,ll>> w;
		while(1){
			if(w.size() >= 100000)break;
			w.push_back({fr , fr + add});
			bad[fr + add] = 1;
			fr++;
			while(bad[fr])fr++;
			add += (k + 1);
		}

		ld lo = 1 + eps,hi = 2 - eps,val = 2;
		{
			for(ll IT=0;IT<100000;IT++){
				ld md = (lo + hi)/2.0;

				ll at = 1;

				for(ll i=0;i<w.size();i++){
					if(ll((i+1) * md) < w[i].first){
						at = 2;
						break;
					}else if(ll((i+1) * md) > w[i].first){
						at = 0;
						break;
					}
				}

				// cerr << md << ' ' << at << '\n';
				if(at == 1){
					val = md;
					break;
				}else if(at == 0)hi = md;
				else if(at == 2)lo = md;
			}

		}
	}


	ll l = val * ord;
	ll r = l + ord * (k + 1);

	// cerr << val << ' ' << ord << ' ' << l << ' ' << r << '\n';

	if(a == l && b == r){
		prt(0);
	}else prt(1);
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

/*
BAD 2 6 1
BAD 4 10 1
BAD 5 13 1
BAD 7 17 1
BAD 8 20 1
BAD 9 23 1
BAD 11 27 1
BAD 12 30 1

BAD 3 12 2
BAD 5 17 2
BAD 6 21 2
BAD 7 25 2
BAD 9 30 2

BAD 4 20 3
BAD 6 26 3

BAD 5 30 4

*/