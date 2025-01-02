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
	freopen("piles.in","r",stdin);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		for(int j=0;j<n;j++)cin>>a[j];
		for(int j=0;j<n;j++)cin>>b[j];
		bool can = true;
		int lst = 0;
		for(int j=0;j<n;j++){
			int need = min(b[j],max(0,a[j] - lst));
			a[j] -= need;
			lst = a[j] + 1;
		}
		for(int j=0;j<n;j++){
			if(a[j] < 0 || (j > 0 && a[j] <= a[j-1])){
				can = 0;
			}
		}
		cout << (can ? "YES\n" : "NO\n");
	}
}	