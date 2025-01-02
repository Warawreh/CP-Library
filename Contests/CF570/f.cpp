#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int bax = 2e5;

void solve(){
	int n;
	cin>>n;
	vector<ll> a(n);
	map<int,bool> h;
	for(int i=0;i<n;i++){
		cin>>a[i];
		h[a[i]] = 1;
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());

	vector<ll> b = a;
	ll ans = a.back();
	vector<ll> x(3);

	x[0] = b.back();
	while(b.size() && x[0]%b.back() == 0)b.pop_back();
	if(b.size()){
		x[1] = b.back();
		while(b.size() && (x[0]%b.back() == 0 || x[1] % b.back() == 0))b.pop_back();
		if(b.size())x[2] = b.back();
	}
	vector<ll> w;
	for(int i=2;i <= 5;i++){
		if(x[0] % i == 0){
			if(h[x[0] / i])w.push_back(x[0] / i);
		}
	}
	sort(all(w));
	ans = max(ans , x[0] + x[1] + x[2]);
	for(int i=0;i<w.size();i++){
		for(int j=i+1;j<w.size();j++){
			if(w[j] % w[i] == 0)continue;
			ans = max(ans , w[i] + w[j]);
			for(int k=j+1;k<w.size();k++){
				if(w[k] % w[i] == 0 || w[k] % w[j] == 0)continue;
				ans = max(ans , w[i] + w[j] + w[k]);
			}
		}
	}

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}