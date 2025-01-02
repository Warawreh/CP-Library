#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,d;
vector<ll> re;
const int nax = 1e6 + 10;
ll dp[nax][3];
vector<ll> a;

ll calc(int i,int r){
	if(i == n){
		if(r)return 2*d;
		else return 0;
	}
	ll &ret = dp[i][r];
	if(ret != -1)return ret;
	ret = 1e18;
	if(r == 0){

		ret = min(ret , re[0] * a[i] + (i + 1 != n ? d : 0LL) + re[2] + calc(i+1,0));

		ret = min(ret , re[1] + re[0] + calc(i+1,1));
		ret = min(ret , re[1] + re[0] + calc(i+1,2));

	}else if(r == 1){

		ret = min(ret , re[0] * a[i] + re[2] + calc(i+1,0) + (i + 1 != n ? d : 0LL));
		ret = min(ret , re[0] * a[i] + re[2] + calc(i+1,1));

		ret = min(ret , re[1] + re[0] + calc(i+1,0) + (i + 1 != n ? d : 0LL));
		ret = min(ret , re[1] + re[0] + calc(i+1,1));
		ret = min(ret , re[1] + re[0] + calc(i+1,2));

		ret += 3*d;

	}else if(r == 2){

		ret = min(ret , re[0] * a[i] + re[2] + calc(i+1,2));
		if(i+1 != n)ret = min(ret , re[1] + re[0] + calc(i+1,2));
		if(i + 1 != n)ret += 2*d;
	}
	// cerr << i << ' ' << r << ' ' << ret << '\n';
	return ret;
}

int main(){
	fast
	re.resize(3);
	cin>>n;
	for(int i=0;i<3;i++)cin>>re[i];
	cin>>d;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << calc(0,0) << '\n';
}