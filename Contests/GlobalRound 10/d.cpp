#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> dp;
int n;
string s;

char f(char c){
	if(c == 'R')return 'L';
	return 'R';
}

int calc(int i,char l,char ll){
	if(i == n)return 0;
	int &ret = dp[i][(l == 'L') + 2 * (ll == 'L')];
	if(ret != -1)return ret;
	ret = 1e9;
	if(l == ll && l == s[i]){
		ret = min(ret , min(1 + calc(i+1,f(s[i]) , l) , 1 + calc(i+1,s[i] , f(l))));
	}else ret = calc(i + 1,s[i],l);
	return ret;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n>>s;

		int ans = 1e9;
		for(int i=0;i<4;i++){
			int w = 0;
			if(i & 1){
				w++;
				s[s.size() - 1] = f(s[s.size() - 1]);
			}
			if(i & 2){
				w++;
				s[s.size() - 2] = f(s[s.size() - 2]);
			}

			dp = vector<vector<int>>(n,vector<int>(4,-1));
			ans = min(ans,w + calc(0,s[s.size() - 1] , s[s.size() - 2]));
			if(i & 1)s[s.size() - 1] = f(s[s.size() - 1]);
			if(i & 2)s[s.size() - 2] = f(s[s.size() - 2]);
		}

		cout << ans << '\n';
	}
}