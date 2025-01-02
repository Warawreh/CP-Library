#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> p;
const int nax = 1e6 + 10; 
int dp[nax][5];
int n,m;


int calc(int i,int t){
	if(i == p[0].size())return t != 3;
	int &ret = dp[i][t];
	if(ret != -1)return ret;

	int g = p[0][i] + (2 * p[1][i]);
	if(t == 3)ret = calc(i + 1 ,g);
	else{
		if(t == 0){
			ret = 1 + calc(i + 1 , g ^ 3); 
		}else if(t == 1){
			ret = 1 + calc(i + 1 , g ^ 2);
		}else if(t == 2){
			ret = 1 + calc(i + 1 , g ^ 1);
		}
	}
	return ret;
}

int main(){
	fast
	cin>>n>>m;
	if(n >= 4 && m >= 4){
		cout << -1 << '\n';
		return 0;
	}
	if(n == 1 || m == 1){
		cout << 0 << '\n';
		return 0;
	}
	vector<string> s(n);
	for(int i=0;i<n;i++)cin>>s[i];
	if(m < n){
		vector<string> nxt(m);
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				// cerr << s[i][j] << '\n';
				nxt[j] += s[i][j];
			}
		}
		s = nxt;
		swap(n,m);
	}
	p.resize(2);
	for(int i=0;i<n-1;i++){
		for(int j=1;j<m;j++){
			int w = (s[i][j] - '0') + (s[i+1][j] - '0') + (s[i][j-1] - '0') + (s[i+1][j-1] - '0');
			p[i].push_back(w%2);
			if(n == 2)p[1].push_back(w%2);
		}
	}
	memset(dp,-1,sizeof(dp));
	int g = p[0][0] + (2 * p[1][0]);
	int ans = calc(1 , g);
	g ^= 1;
	ans = min(ans , 1 + calc(1 , g));
	g ^= 1;
	g ^= 2;
	ans = min(ans , 1 + calc(1 , g));
	g ^= 2;
	g ^=3;
	ans = min(ans , 1 + calc(1 , g));
	cout << ans << '\n';
}