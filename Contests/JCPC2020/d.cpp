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
	#ifndef LOCAL
		freopen("card.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<int,int> c;
		vector<int> a(2*n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			c[a[i]] = 1;
		}
		for(int i=0;i<n;i++){
			cin>>a[i+n];
			c[a[i+n]] = 2;
		}
		sort(all(a));
		int win = 1;
		for(int i=0;i<n;i++){
			if(c[a[i]] == 2 && c[a[2*n-i-1]] == 2){
				win = 1;
				break;
			}else if(c[a[i]] == 1 && c[a[2*n-i-1]] == 1){
				win = 0;
				// cerr << a[i] << ' ' << a[2*n-i-1] << '\n';
				break;
			}
		}
		cout << (win ? "Rashad" : "Youssef") << '\n';
	}
}