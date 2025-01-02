#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
	if(sum % n){
		cout << -1 << '\n';
		return;
	}
	int to = sum / n;
	vector<vector<int>> e;
	for(int i=1;i<n;i++){
		int need = (i+1) - a[i] % (i+1);
		if(a[i] % (i+1)){
			e.push_back({1,i+1,need});
			a[0] -= need;
			a[i] += need;
		}
		int give = a[i] - a[i] % (i+1);
		if(give){
			e.push_back({i+1,1,give / (i+1)});
			a[0] += give;
			a[i] -= give;
		}

	}
	for(int i=1;i<n;i++){
		int need = to - a[i];
		e.push_back({1,i+1,need});
		a[0] -= need;
		a[i] += need;
	}
	for(int i=0;i<n;i++){
		// if(a[i] != to){
		// 	cout << "-1\n"; 
		// }
		// cerr << a[i] << ' ';
		assert(a[i] == to);
	}
	// assert(e.size() <= 3*n);
	cout << e.size() << '\n';
	for(vector<int> x : e){
		cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}