#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int oo = 1e9;

vector<int> dp;
int n,k;
string s;

int calc(int idx){
	if(idx >= n)return 0;
	int &ret = dp[idx];
	if(ret != -oo)return ret;
	ret = 1e9;
	int bit = s[idx] == '1';
	if(bit == 1){
		ret = min(-1 , calc(idx + k) - 1);
		// cerr << idx << ' ' << bit << '\n';
		return ret ;
	}else{
		ret = min(0 , calc(idx + k) + 1);
		return ret;
	}
	return ret;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k>>s;
		vector<int> p(k),z(k);
		dp = vector<int>(n,-oo);
		int ans = 0;
		for(int i=0;i<n;i++){
			int bit = s[i] == '1';
			p[i%k] += bit;
			z[i%k] += !bit;
			ans += bit;
		}
		int sum = ans;
		int turn_off = 0;
		// cout << sum << ' ' << calc(5) << '\n';
		// break;
		for(int i=n-1;i>=0;i--){
			ans = min(ans , sum + calc(i));
		}
		cout << ans << '\n';
	}
}