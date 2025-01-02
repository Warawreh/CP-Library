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
		bool good = true;
		vector<int> v;
		int at = n-1,sub = 1e9;
		int tot = 0;
		int lst = 0;
		for(int i=n-1;i>=0;i--){
			int need = a[i] - l[i];
			r[i] = need;
		}
		for(int i=1;i<n;i++){
			int dif;
			dif = l[i] - l[i-1];
			dif = max(dif , 0);
			r[i] += dif;
			l[i] -= dif;


			dif = r[i-1] - r[i];
			dif = max(dif , 0);
			l[i] -= dif;
			r[i] = max(r[i] , r[i-1]);
		}
		int vv = 1e9;
		for(int i=0;i<n;i++){
			int more = r[i] + l[i] - a[i];
			// l[i] -= more;
			// cerr << l[i] << ' ' << r[i] << ' ' << a[i] << '\n';
			if(l[i] < 0)good = false;
			vv = more;
		}
		
		cout << (good ? "Yes\n" : "No\n");
	}
}