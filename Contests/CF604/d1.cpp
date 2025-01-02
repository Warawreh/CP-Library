#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int nax = 2020;

int n;
string s;
vector<vector<int>> dp;
int lvl;

int calc(int i,int d){
	d = max(d , -lvl);
	if(i == n)return (d <= -lvl);
	int &ret = dp[i][lvl + d];
	if(ret != -1)return ret;
	ret = 0;
	if(s[i] == '('){
		if(d <= 0){
			ret = (ret + calc(i+1,d))%mod;
		}else{
			ret = (ret + calc(i+1,d-1))%mod;
		}
	}else if(s[i] == ')'){
		if(d <= 0){
			ret = (ret + calc(i+1,d-1))%mod;
		}else{
			ret = (ret + calc(i+1,d))%mod;
		}
	}else{
		assert(s[i] == '?');
		ret = (ret + calc(i + 1 , d))%mod;
		ret = (ret + calc(i + 1 , d-1))%mod;
	}
	return ret;
}

int main(){
	fast
	cin>>s;
	n = s.size();
	int lst = 0;
	int ans = 0;
	for(int d=n/2;d>=1;d--){
		lvl = d;
		dp = vector<vector<int>>(n,vector<int>(2*lvl + 2,-1));
		int cur = calc(0,d);
		// cerr << d << ' ' << ans << ' ' << lst << ' ' << cur << '\n';
		ans = (ans + ((cur - lst) * d)%mod)%mod;
		ans = (ans + mod)%mod;
		lst = cur;
	}
	cout << ans << '\n';
}