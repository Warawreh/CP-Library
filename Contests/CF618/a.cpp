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
	vector<int> b(33);
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		for(int k=0;k<=30;k++){
			if((a[i].first >> k) & 1)b[k]++;
		}
		a[i].second = a[i].first;
	}
	for(int i=0;i<n;i++){
		for(int k=0;k<=30;k++){
			if(((a[i].first >> k) & 1) && b[k] > 1)
				a[i].first -= (1<<k);
		}
		// cerr << a[i].first << ' ';
	}

	sort(all(a));
	reverse(all(a));
	for(auto i : a)cout << i.second << ' ';
}