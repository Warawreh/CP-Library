#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,k;
	cin>>n>>k;

	vector<int> a;
	int z = 0;
	for(int i=0;i<n;i++){
		int d;
		cin>>d;
		if(d == 0){
			z++;
			continue;
		}
		a.push_back(d);
	}
	if(z > 1){
		cout << -1 << '\n';
		return;
	}
	if(a.size() == 0){
		cout << 1 << '\n';
		return;
	}
	if(k == 1){
		if(a.size() > 1 || a[0] != 1){
			cout << -1 << '\n';
		}else{
			cout << 2 << '\n';
		}
		return;
	}

	map<int,ll> f;
	f[1] = 0;
	for(int i=0;i<a.size();i++){
		f[a[i]]++;
	}


	int lst = -1;
	ll ans = 0,hv = 0;
	for(auto it = f.rbegin() ; it != f.rend();it++){
		auto cur = *it;
		if(lst != -1){
			
			int to = max(cur.first , lst - 20);
			for(int i = lst;i > to ;i--){
				ans += hv;
				hv = (hv + k - 2) / (k - 1);
			}
			ans += to - cur.first;
			if(k == 2 && hv == 2)ans += to - cur.first;

			if(cur.first == 1 && hv > k){
				cout << -1 << '\n';
				return;
			}

		}
		hv = max(hv , cur.second);
		lst = cur.first;

	}

	cout << ans + 1 + hv << '\n';

}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/