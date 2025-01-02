#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int nax = 6060;

int dp[nax][nax];
string s;

int calc(int l,int r){
	if(l >= r)return 0;
	int &ret = dp[l][r];
	if(ret != -1)return ret;
	ret = calc(l+1,r-1) + abs(s[l] - s[r]);
	return ret;
}

void solve(){
	int q;
	cin>>s>>q;
	int n=s.size();
	memset(dp,-1,sizeof(dp));
	while(q--){
		int l,r,m;
		cin>>l>>r>>m;
		l--;r--;
		int md,lo=0,hi=n,k=0;
		while(lo <= hi){
			md = (lo + hi)/2;
			int ans = calc(l+md,r-md); 
			if(ans <= m){
				hi = md-1;
				k = md;
			}else{
				lo = md+1;
			}
		}
		r -= k;l+=k;
		printf("%d\n", r-l+1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	// freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}