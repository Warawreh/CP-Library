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
	sieve((int)1e7 + 10);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> g;
		for(int i=1;i<=1e5;i++){
			if(is_composite[i] == false)continue;
			ll val = i*(n-1);
			if(is_composite[val + 1] == false){
				g.resize(n,vector<int>(n,i));
				for(int j=0;j<n;j++)g[j][j] = 1;
				break;
			}
		}
		assert(g.size());
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << g[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}