#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2100;

vector<string> s;
int n,m;
int dp[11][nax];

int calc(int idx,int mask){
	if(idx == m)return 1;
	int &ret = dp[idx][mask];
	if(ret != -1)return ret;
	ret = 0;
	for(char c = 'a';c<='z';c++){
		bool good=1;
		int tmp = mask;
		for(int i=0;i<n;i++){
			string a = s[i];
			if(a[idx] != c && (mask>>i) & 1){
				good = 0;
				break;
			}
			if(a[idx] != c)
				tmp |= (1<<i);
		}
		if(good){
			// cerr << idx << ' ' << mask << ' ' << c << ' ' << tmp << '\n';
			ret |= calc(idx + 1,tmp);
		}
	}
	return ret;
}

void build(int idx,int mask){
	for(char c = 'a';c<='z';c++){
		bool good=1;
		int tmp = mask;
		for(int i=0;i<n;i++){
			string a = s[i];
			if(a[idx] != c && (mask>>i) & 1){
				good = 0;
				break;
			}
			if(a[idx] != c)
				tmp |= (1<<i);
		}
		if(good){
			if(calc(idx + 1,tmp)){
				cout << c;
				build(idx+1,tmp);
				break;
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	s = vector<string>(n);
	for(int i=0;i<n;i++)cin>>s[i];
	memset(dp,-1,sizeof(dp));
	if(calc(0, 0)){
		build(0,0);
		cout << '\n';
	}else{
		cout << "-1\n";
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}