#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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



int main(){
	fast
	sieve((int)3164);
	

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans = 0;
		map<int,bool> hv;
		// vector<vector<int>> dp(k+1,vector<int>(n,1e9));
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			int v = 1;
			for(int p : prime){
				if(p > a)break;
				if(a % p)continue;
				int cnt = 0;
				while(a % p == 0){
					a/=p;
					cnt++;
				}
				if(cnt){
					cnt%=2;
					if(cnt)v*=p;
				}
			}
			if(a)v*=a;

			if(hv[v]){
				if(k){
					k--;
				}else{
					
				}
				ans++;
				hv.clear();
			}
			hv[v] = 1;
		}
		cout << ans + 1 << '\n';
	}
}