#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int nax = 1e6 + 10;
map<int,int> dp[nax];
map<int,bool> vis[nax];
int n;

int calc(int i,int j){
	if(min(i , j) == 3)return 1;
	if(i < j)swap(i,j);
	int &ret = dp[i][j];
	if(vis[i][j])return ret;
	vis[i][j] = 1;
	ret = 0;
	int nxt = min(i,j) - 1;
	if(i % nxt <= 2 || i == n+1){
		ret = (ret + calc(nxt , j))%mod;
	}
	if(j % nxt <= 2 || j == n+1){
		ret = (ret + calc(i , nxt))%mod;
	}
	return ret;
}

int main(){
	fast
	cin>>n;

	cout << (calc(n+1,n+1) * 1LL * n)%mod << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/