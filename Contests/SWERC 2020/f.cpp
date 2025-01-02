#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2023;
int dp[nax][nax][2];
int R,n,m;

int calc(int two,int one,int tr,int u){
	if(two < 0 || one < 0)return 0;
	if(u == 0)return 1;

	int &ret = dp[two][one][tr];
	if(ret != -1)return ret;
	ret = 0;

	if(u == R){
		ret = (calc(two - 1 , one + 1 , 1 , u - 1) * 1LL * two)%m;
		ret = (ret + (calc(two,one - 1,1 , u-1) * 1LL * one)%m)%m;

		return ret;
	}

	ret = (calc(two , one + 1 , tr , u - 1) * 1LL * two)%m;
	ret = (ret + (calc(two+1,one - 1,tr , u - 1) * 1LL * one)%m)%m;

	// cerr << two << ' ' << one << ' ' << tr << ' ' << u << ' ' << ret << '\n';
	return ret;
}

int main(){
    fast
    cin>>R>>n>>m;
    if(R == n){
    	if(n == 1)cout << 1 << '\n';
    	else cout << 0 << '\n';
    	return 0;
    }

    memset(dp,-1,sizeof(dp));
    cout << calc(1,0,0,n-1) << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/