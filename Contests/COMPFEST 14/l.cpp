#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int iinf = (int)1e9 + 10;
const ll linf = (ll)1e18 + 10;

const int multitest = 0;

const int maxn = 1e5 + 10;
int f[maxn];

void inc(int i, int delta){
	for (; i < maxn; i = i | (i + 1)){
		f[i] += delta;
	}
}

int sum(int r){
	int res = 0;
	for (;r >= 0; r = (r&(r+1)) - 1){
		res += f[r];
	}
	return res;
}

ll sort_num(vector <ll> & v){
	int n = v.size();
	vector <pair<ll, int>> u(n);
	for (int i = 0; i < n; i++){
		u[i] = {v[i], i};
	}
	sort(all(u));
	ll ans = 0;
	for (auto [val, ind] : u){
		ans += ind - sum(ind);
		inc(ind, 1);
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector <int> a(n); vector <ll> p(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		p[i] = a[i] + (i == 0 ? 0 : p[i-1]);
	}

	for (int i = 0; i < n; i++){
		if (p[i] < 0){
			cout << -1 << "\n";
			return;			
		}
	}

	for (int i = 0; i < n-1; i++){
		if (p[n-1] < p[i]){
			cout << -1 << "\n";
			return;
		}
	}
	p.pop_back();
	cout << sort_num(p) << "\n";
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (multitest) cin >> t;
    while (t--){
        solve();
    }
 
    return 0;
} 