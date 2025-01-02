#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll p10[20];
ll n,s,ans;
int dp[20][200][2];
string num;

int calc(int i,int sum,int t){
	if(sum > s)return 0;
	if(i == -1)return (sum <= s);
	int &ret = dp[i][sum][t];
	if(ret != -1)return ret;
	ret = 0;
	for(int j=0;j<10;j++){
		if(j < num[i] - '0' && t == 0)continue;
		ret |= calc(i-1,sum+j,t | (j > num[i] - '0'));
	}
	return ret;
}

void build(int i,int sum,int t){
	if(i == -1)return;
	for(int j=0;j<10;j++){
		if(j < num[i] - '0' && t == 0)continue;
		if(calc(i-1,sum+j,t | (j > num[i] - '0'))){
			ans += p10[i] * j;
			build(i-1,sum+j,t | (j > num[i] - '0'));
			break;
		}
	}
}

int main(){
	fast
	p10[0] = 1;
	for(int i=1;i<=18;i++)p10[i] = 10LL * p10[i-1];
	int t;
	cin>>t;
	while(t--){
		cin>>n>>s;
		num = to_string(n);
		while(num.size() <= 18)num = "0" + num;
		reverse(all(num));
		ans = 0;
		memset(dp,-1,sizeof(dp));
		build(18,0,0);

		cout << ans - n << '\n';
	}	
}