#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prime;
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

int main(){
    fast
    sieve(400);
 	
 	ll ans = 0;
 	for(int i=2;i<=1e5;i++){

 		int t = i;
 		int cnt = 0;
 		for(int j : prime){
 			if(t % j == 0){
 				cnt++;
 				while(t % j == 0)t /= j;
 			}
 		}
 		if(t > 1)cnt++;
 		ans += (1 << cnt) - 1;
 	}   
 	cout << ans << '\n';
}
