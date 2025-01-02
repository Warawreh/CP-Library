#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2e5 + 10;
vector<int> f[nax];
int limit[nax];

void solve(){
	int n;
	cin>>n;
	// n = 1e5;
	int rem = n;
	vector<int> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i];
		// p[i] = uniform_int_distribution<int>(1, 1e9)(rng);
	}

	for(int i=0;i<(1<<17);i++){
		f[i].clear();
		limit[i] = 2e9;
	}

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		// x = uniform_int_distribution<int>(1, 1e5)(rng);
		limit[x] = min(limit[x] , p[i]);
		f[x].push_back(p[i]);
	}
	const int N = 17;
	for(int i = 0;i < N; ++i)
		for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i)){
				int x = mask ^ (1<<i);
				for(int v : f[x]){
					if(v < limit[mask])f[mask].push_back(v);
				}
			}
		}


	cout << f[(1<<N)-1].size() << '\n';

}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/