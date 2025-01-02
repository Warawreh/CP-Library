#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
ll dp[33][8];
vector<pair<int,int>> r;
int n = 3;

ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}

ll calc(int i,int m){
	if(i == -1)return 1;

	ll &ret = dp[i][m];
	if(ret != -1)return ret;
	ret = 0;

	ll nm = m;
	for(int j=0;j<n;j++){
		if((r[j].second >> i) & 1)nm |= (1 << j);
	}
	ret = calc(i - 1 , nm);

	for(int x=0;x<3;x++){
		for(int y=x+1;y<3;y++){

			if(((r[x].second >> i) & 1) || ((m >> x) & 1)){
				if(((r[y].second >> i) & 1) || ((m >> y) & 1)){
					int z = 0 + 1 + 2 - x - y;
					int nm = m;
					if(((r[z].second >> i) & 1) == 1)nm |= (1 << z);
					ret = (ret + calc(i - 1, nm));

				}
			}

		}
	}

	return ret;
}

int main(){
    fast
    r.resize(n);
    ll tot = 1;
    for(int i=0;i<n;i++){
    	cin>>r[i].first >>r[i].second;
    	tot = (tot * (r[i].second - r[i].first + 1))%mod;
   		r[i].first--;
    }

    ll ways = 0;
    for(int msk=0;msk<8;msk++){

    	ll tot = 1;
	    int cnt = 0;
	    for(int j=0;j<3;j++){
	    	if((msk >> j) & 1){
	    		swap(r[j].first , r[j].second);
	    		cnt++;
	    	}
	    	tot = (tot * (r[j].second + 1))%mod;
	    }

	    memset(dp,-1,sizeof(dp));
	   	ll v1 = calc(31 , 0);
	   	v1 = (tot - v1 + mod)%mod;
	   	if(cnt % 2 == 0)ways = (ways + v1)%mod;
	   	else ways = (ways - v1 + mod)%mod;

	   	// cerr << msk << ' ' << cnt << ' ' << v1 << ' ' << ways << ' ' << tot << '\n';
	   	// break;

		for(int j=0;j<3;j++){
	    	if((msk >> j) & 1){
	    		swap(r[j].first , r[j].second);
	    	}
	    }

    }
   	cout << (ways * POW(tot , mod-2))%mod << '\n';

}
