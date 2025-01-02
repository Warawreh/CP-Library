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
	vector<ll> a = {1,1};
	while(a.size() <= 100){
		a.push_back(a[a.size() - 1] + a[a.size() - 2]);
		cout << a.back() << '\n';
	}
}