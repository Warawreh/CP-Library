#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int nax = 1e5 + 10;

ll hv[nax];
vector<vector<int>> dev;

void solve(){
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	ll ans = 0;

	set<int> remAf;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);

		for(int d : dev[a[i]]){	
			remAf.insert(d);
			hv[d] = (hv[d] + a[i])%mod;
		}
	}


	for(int i=0;i<n;i++){
		vector<int> d = dev[a[i]];
		vector<int> old;

		reverse(all(d));

		for(int x=0;x<d.size();x++){

			old.push_back(hv[d[x]]);

			for(int y=0;y<x;y++){
				if(d[y] % d[x] != 0)continue;
				hv[d[x]] = (hv[d[x]] - hv[d[y]] + mod)%mod;
			}

			ll val = a[i] / d[x];

			ans = (ans + (val * hv[d[x]])%mod)%mod;

		}

		for(int x=0;x<d.size();x++)hv[d[x]] = old[x];
	}
	printf("%lld\n", ans);


	for(int it : remAf)hv[it] = 0;
}

int main(){
	freopen("lcm.in","r",stdin);	
	
	dev.resize(nax);

	for(int i=1;i<nax;i++){
		for(int j=i;j<nax;j+=i)
			dev[j].push_back(i);
	}

	int t;
	scanf("%d",&t);
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/