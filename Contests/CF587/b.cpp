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
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second = i;
	}
	sort(all(a));
	reverse(all(a));
	vector<int> seq;
	ll ans = 0;
	for(int i=0;i<n;i++){
		seq.push_back(a[i].second + 1);
		ans += i * a[i].first + 1;
	}
	cout << ans << '\n';
	for(int i : seq)cout << i << ' ';
}