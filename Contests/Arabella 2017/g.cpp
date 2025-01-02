#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
(n * (n+1) / 2) * (m * (m+1) / 2)
*/

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vector<pair<ll,ll>> p(k);
		for(int i=0;i<k;i++){
			cin>>p[i].first>>p[i].second;
		}

		ll ans = n * 1LL * (n+1) / 2 * m * 1LL * (m+1) / 2;
		for(int mask=1;mask<(1<<k);mask++){

			int cnt = 0;
			pair<ll,ll> tl = {n,m},br = {1,1};
			for(int i=0;i<k;i++){
				if((mask >> i) & 1){
					cnt++;
					tl.first = min(tl.first , p[i].first);
					tl.second = min(tl.second , p[i].second);

					br.first = max(br.first , p[i].first);
					br.second = max(br.second , p[i].second);
				}
			}

			ll val = tl.first * tl.second * (n - br.first + 1) * (m - br.second + 1);

			if(cnt % 2 == 1)ans -= val;
			else ans += val;
		}
		cout << ans << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/