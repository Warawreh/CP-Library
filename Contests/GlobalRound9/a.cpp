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
		vector<int> a(n);
		int x=0,y=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i] = abs(a[i]);
			if(i){
				if(a[i] - a[i-1] == 0){
					x++;y++;
				}else if(a[i] - a[i-1] > 0)x++;
				else y++;
			}
		}
		for(int i=0;i<n-1;i++){
			if(x * 2 + 1 >= n && y * 2 + 1 >= n)break;
			if(a[i+1] - a[i] < 0 && x * 2 + 1 < n){
				a[i] = -a[i];
			}
			if(a[i+1] - a[i] > 0 && y * 2 + 1 < n){
				a[i] = -a[i];
			}
			x = y = 0;
			for(int j=1;j<n;j++){
				if(a[j] - a[j-1] == 0){
					x++;y++;
				}else if(a[j] - a[j-1] > 0)x++;
				else y++;
			}
		}
		for(int i=0;i<n;i++)cout << a[i] << ' ';
		cout << '\n';
	}
}