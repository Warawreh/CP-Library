#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
const int mod = 1e9+7;
 
map<ll,int> f;
 
ll fib(ll n){ 
    if(n == 0)return 0; 
    if(n == 1)return 1;
    if(n == 2)return 1;
  
  	if(f[n] != 0)return f[n];
  	
    ll k = (n & 1)? (n+1)/2 : n/2;  
    ll res = (n & 1)? (((fib(k)*fib(k))%mod + (fib(k-1)*fib(k-1))%mod))%mod
    : (((2*fib(k-1) + fib(k))%mod)*fib(k))%mod;
  	f[n] = res;
    return res;
} 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// #endif
	ll n;
	cin>>n;
	cout << fib(n) << endl;
}