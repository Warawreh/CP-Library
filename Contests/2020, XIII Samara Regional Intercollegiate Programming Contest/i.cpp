#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int nax = 2e5 + 100;
set<int> color[nax];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n;
	cin>>n;
	vector<int> a(n),c(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		color[c[i]].insert(i);
	}
	vector<int> id(n);
	iota(all(id) , 0);
	sort(all(id) , [&](int i,int j){
		if(a[i] == a[j])return i < j;
		return a[i] < a[j];
	});
	bool can = 1;
	for(int i : id){
		int at = *color[c[i]].begin();
		// cout << i << ' ' << at << '\n';
		// if(a[at] != a[i])
		if(at != i){
			can = 0;
			break;
		}
		color[c[i]].erase(color[c[i]].begin());
	}
	cout << (can ? "YES\n" : "NO\n");
}