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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n*=2;
		vector<int> a(n),at(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			at[--a[i]] = i;
		}
		bitset<2020> b;
		b[0] = 1;
		for(int i=n-1;i>=0;i--){
			if(a[at[i]] == -1)continue;
			int sz = 0;
			for(int j=at[i];j<n;j++){
				if(a[j] > i || a[j] == -1){
					sz = j - at[i];
					break;
				}else if(j == n-1)sz = j-at[i] + 1;
				a[j] = -1;
			}
			a[at[i]] = -1;
			// cerr << i << ' ' << sz << '\n';
			b |= (b << sz);
		}
		n/=2;
		cout << (b[n] ? "Yes\n" : "No\n");
	}
}