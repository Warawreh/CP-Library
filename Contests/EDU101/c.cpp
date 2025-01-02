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
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		vector<int> r = {-(k-1) , k - 1};
		bool good = true;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i == 0){
				r = {a[i] - (k-1) , a[i] + (k - 1)};
			}else{
				if(i == n-1){
					if(a[i] > r[1] || a[i] < r[0])good = false;
				}else if(i){
					// cerr << r[0] << ' ' << r[1] << ' ' << a[i] << '\n';
					if(a[i] > r[1] || a[i] + k - 1 < r[0])good = false;
				}
				r = {max(r[0] - k + 1 , a[i] - (k-1)) , min(r[1] + (k - 1) , a[i] + 2*(k-1))};
			}
		}
		cout << (good ? "YES\n" : "NO\n");
	}
}