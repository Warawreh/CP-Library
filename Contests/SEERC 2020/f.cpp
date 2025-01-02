#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 3003;
const int mod = 1e9 + 7;
int dp[nax][nax][2];
int n;
vector<int> a,at;
vector<pair<int,int>> b;

int calc(int i,int r,int rev){
	if(i == n)return 1;
	if(i == r)rev = 1;
	int &ret = dp[i][r][rev];
	if(ret != -1)return ret;

	ret = 0;
	if(i < r){
		ret = (ret + calc(i+1,r,rev))%mod;
	}
	
	for(int j=max(i,r);j<b[i].second;j++){
		ret = (ret + calc(i+1,j+1,0))%mod;
	}

	if(rev)
		for(int to=0;to<a[i];to++){
			int p = at[to];
			if(p > r && b[p].first <= i){
				ret = (ret + calc(i+1,p,1))%mod;
			}
		}
	// cerr << i << ' ' << r << ' ' << ret << '\n';

	return ret;
}

void solve(){
	cin>>n;
	a.resize(n);
	b = vector<pair<int,int>>(n,{-1,n});
	at.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
		at[a[i]] = i;
		for(int j=i;j>=0;j--){
			if(a[j] < a[i]){
				b[i].first = j;
				break;
			}
		}
		for(int j=i;j>=0;j--){
			if(a[i] < a[j]){
				b[j].second = min(b[j].second , i);
			}
		}
	} 

	memset(dp,-1,sizeof(dp));
	cout << calc(0,0,1) << '\n';
}

int main(){
    fast
	int t;
	// cin>>t;
	t = 1;
	while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/