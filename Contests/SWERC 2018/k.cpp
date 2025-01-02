#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 702;
int dp[nax][nax];

string s;
vector<vector<int>> d;
int n;

void calcD(){
	d.resize(n + 1);
	for(int i=2;i<=n;i++){
		d[i] = {1};
		for(int j=2;j<i;j++){
			if(i % j == 0)d[i].push_back(j);
		}
	}
}

int calc(int l,int r){
	if(l == r)return 1;
	int &ret = dp[l][r];
	if(ret != -1)return ret;
	ret = 1e9;
	int sz = r - l + 1;
	for(int x : d[sz]){
		bool good = true;
		int at = 0;
		for(int i=l+x;i<=r;i++){
			if(s[i] != s[l + at]){
				good = false;
				break;
			}

			at++;
			at %= x;
		}
		if(good){
			ret = min(ret , calc(l , l + x - 1));
		}
	}

	for(int i=l+1;i<=r;i++){
		ret = min(ret , calc(l , i-1) + calc(i , r));
	}

	return ret;
}

int main(){
    fast
    cin>>n>>s;
    memset(dp,-1,sizeof(dp));
    calcD();

    cout << calc(0,n-1) << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/