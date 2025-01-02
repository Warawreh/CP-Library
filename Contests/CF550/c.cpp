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
	map<int,int> f;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		f[a[i]]++;
		if(f[a[i]] == 3){
			cout << "NO\n";
			return 0;
		}
	}
	sort(all(a));
	vector<int> inc,dec;
	for(int i=0;i<n;i++){
		if(inc.size() && inc.back() == a[i])dec.push_back(a[i]);
		else inc.push_back(a[i]);
	}
	reverse(all(dec));
	cout << "YES\n";
	cout << inc.size() << '\n';
	for(int i : inc)cout << i << ' ';
	cout << '\n';
	cout << dec.size() << '\n';
	for(int i : dec)cout << i << ' ';
	cout << '\n';
}