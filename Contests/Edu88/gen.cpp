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
	n = uniform_int_distribution<int>((int)5e4, (int)1e5)(rng);
	cout << n << '\n';
	vector<int> a = {-29 , 30 ,30};
	for(int i=0;i<n;i++){
		if(i)cout << ' ';
		cout << uniform_int_distribution<int>(-30, 30)(rng);
	}
	cout << '\n';
}