#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll oo = 1e18;
ll cost[26][26];
int n,m;
string s;
const int nax = 1e5 + 10;
ll dp[nax][40];

ll calc(int i,int cur){
	if(i == n){
		if(cur == 0)return 0;
		else return oo;
	}
	ll &ret = dp[i][cur];
	if(ret != -1)return ret;
	ret = oo;
	for(int j=0;j<=s[i] - 'a';j++){
		int nVal = cur ^ (s[i] - 'a') ^ j;
		// if(i == 2 && cur == 0)cerr << i << ' ' << nVal << '\n';
		ret = min(ret , calc(i + 1,nVal) + cost[s[i] - 'a'][j]);
	}
	return ret;
}

int main(){
	fast
	freopen("win.in","r",stdin);	
	cin>>n>>m>>s;

	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++){
			if(i == j)cost[i][j] = 0;
			else cost[i][j] = oo;
		}

	for(int i=0;i<m;i++){
		char a,b;
		ll k;
		cin>>a>>b>>k;
		// if(a > b)swap(a,b);
		// cerr << ' ' << a << ' ' << b << '\n';
		cost[a - 'a'][b - 'b'] = min(cost[a - 'a'][b - 'b'] , k);
		cost[b - 'a'][b - 'b'] = min(cost[b - 'a'][b - 'b'] , k);
	}
	int cur = 0;
	for(int i=0;i<n;i++){
		cur ^= (s[i] - 'a');
	}
	memset(dp,-1,sizeof(dp));

	ll ans = calc(0,cur);
	if(ans == oo)ans = -1;
	cout << ans << '\n';
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/