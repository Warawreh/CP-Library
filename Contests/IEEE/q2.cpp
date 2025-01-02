#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld eps = 1e-10;

int main(){
    fast
    cout << setprecision(40) << fixed;
    for(int k=0;k<=20;k++){

	   	

		ll fr = 1;
		unordered_map<ll , bool> bad;
		ll add = (k + 1);
		vector<pair<ll,ll>> w;
		while(1){
			if(w.size() >= 1000000)break;
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

		cout << val << ',';
    }

}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/