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
	is_composite[0] = is_composite[1] = true;
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main(){
	sieve(1e7 + 10);
	fast
	int n;
	cin>>n;
	for(int i=2;i<=n-2;i++){
		if(is_composite[i] == false && is_composite[n-i] == false){
			cout << i << ' ' << n-i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}