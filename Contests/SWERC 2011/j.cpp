#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

vector<int> prime,val;
vector<bool> is_composite;

void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

const int nax = 3000;
int pp[nax][nax];

ll POW(ll a,ll b){
	if(b < nax && a < nax && pp[b][a])return pp[b][a];
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b%2)res = (res * a)%mod;
	if(b < nax && a < nax)
		pp[b][a] = res;
	return res;
}

int main(){
	fast
	sieve((1e7 + 1));
	while(1){
		int n;
		cin>>n;
		if(!n)break;
		ll res = 1;
		for(ll i:prime){
			if(i > n/2)break;
			int cnt = 0;
			for(ll j=i;j<=n;j*=i){
				cnt += n / j;
			}
			cnt -= cnt%2;
			res = (res * POW(i , cnt))%mod;
		}
		cout << (res)%mod << '\n';
	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/