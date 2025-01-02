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
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	ll VAL = (ll)1e9;
	ll ans = 0;
	ll mx = 0;
	vector<int> id;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans += a[i] * VAL;
		if(a[i] == mx){
			id.push_back(i);
		}else if(a[i] > mx){
			mx = a[i];
			id.clear();
			id.push_back(i);
		}
	}
	ans += mx * VAL * (m-1);
	ll sum = 0;
	for(int i=0;i<m;i++){
		cin>>b[i];
		sum += b[i];
	}
	ll lst = b.back();
	sum += id[0] * b[0];
	sort(all(b));
	ll take = id.back() - id[0] + 1;
	sum += b.back() * (take - 1);
	sum += lst * (n - id.back() - 1);
	cout << ans + sum << '\n';
}