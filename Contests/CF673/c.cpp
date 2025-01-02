#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n;
	cin>>n;
	vector<vector<int>> a(1,vector<int>(n));
	for(int i=0;i<n;i++){
		cin>>a[0][i];
	}
	int v = 0;
	ll ans = 0;
	for(int k=30;k>=0;k--){
		ll cur = 0,cur2 = 0;
		for(vector<int> x : a){
			int o = 0,z=0;
			for(int i : x){
				if((i >> k) & 1 == 1){
					o++;
					cur2 += z;
				}else{
					z++;
					cur += o;
				}
			}
		}
		// cerr << a[0].size() << ' ' << cur << ' ' << cur2 << '\n';
		ans += min(cur,cur2);
		bool c = 0;
		if(cur > cur2){
			v += (1<<k);
			c = 1;
		}
		vector<vector<int>> nxt;
		for(vector<int> x : a){
			vector<int> l,r;
			for(int i : x){
				if(c)i ^= (1<<k);
				if((i >> k) & 1)l.push_back(i);
				else r.push_back(i);
			}
			if(l.size())nxt.push_back(l);
			if(r.size())nxt.push_back(r);
		}

		a = nxt;
	}
	
	cout << ans << ' ' << v << '\n';
}