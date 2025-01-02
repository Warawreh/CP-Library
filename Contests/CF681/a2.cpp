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
		vector<int> a(n),l(n),r(n);
		int x = 1e9;
		for(int i=0;i<n;i++){
			cin>>a[i];
			x = min(x , a[i]);
			l[i] = x;
		}
		x = 1e9;
		int bad = 0;
		for(int i=n-1;i>=0;i--){
			x = min(x , a[i]);
			r[i] = x;
			bad += r[i] < a[i];
		}
		bool good = false;
		int at = 0;
		for(int i=0;i<n;i++){
			while(at < i && a[at] > a[i]){
				bad += l[at] < a[at];
				at++;
			}
			bad -= r[i] < a[i];
			if(bad == 0 && r[i] + l[i] >= a[i])good = true;
		}
		cout << (good ? "Yes\n" : "No\n");
	}
}