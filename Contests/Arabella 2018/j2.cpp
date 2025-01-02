#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1000;
int dp[nax][nax];

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		int c=0;
		for(ll i=0;i<64;i++){
			if((n >> i) & 1)c++;
		}
		cout << n + 1 - (1LL << c) << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/