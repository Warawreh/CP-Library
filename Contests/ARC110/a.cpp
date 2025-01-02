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

	int n;
	cin>>n;
	sieve(n + 1);
	ll ans = 1;
	vector<int> need(33);
	for(int i=2;i<=n;i++){
		int tmp = i;
		for(int x : prime){
			int cnt = 0;
			while(tmp % x == 0){
				tmp/=x;
				cnt++;
			}
			need[x] = max(need[x] , cnt);
		}
		assert(tmp == 1);
	}
	for(int i=2;i<=n;i++){
		for(int a =0;a<need[i];a++)
			ans *= i;
	}
	ans++;
	// for(int i=2;i<=n;i++)
	// 	cerr << ans% i << ' ' ;
	cout << ans << '\n';
}