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
	vector<int> a(n);
	vector<int> b(31);
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			b[j] += ((a[i]>>j)&1);
		}
	}
	for(int i=0;i<31;i++){

		if(b[i] % 2 && (n - b[i])%2){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	vector<vector<int>> ans;
	int cnt = 0;
	for(int i=1;i+1<n;i+=2){
		int x = a[0]^a[i]^a[i+1];
		a[0] = a[i+1] = a[i] = x;
		cnt++;
		ans.push_back({1,i+1,i+2});
	}
	for(int i=1;i+1<n-2;i+=2){
		int x = a[0]^a[i]^a[i+1];
		a[0] = a[i+1] = a[i] = x;
		cnt++;
		ans.push_back({1,i+1,i+2});
	}

	cout << ans.size() << '\n';
	for(int i=0;i<ans.size();i++){
		for(int a : ans[i]){
			cout << a << ' ';
		}
		cout << '\n';
	}

	for(int i=0;i<n;i++){
		// cerr << a[i] << ' ';
		assert(a[i] == a[0]);
	}

}