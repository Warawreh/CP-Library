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
		int ans = 0;
		int mn = 0;
		int pr = 1,ch = 0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			if(!i)continue;
			// cerr << a << ' ' << mn << ' ' << pr << '\n';
			if(a < mn){
				pr--;
				if(pr == 0){
					ans++;
					pr = ch;
					ch = 1;
				}else{
					ch++;
				}
				mn = a;
			}else{
				ch++;
			}
			mn = max(mn , a);
			// cerr << a[i] << ' ' << mn << '\n';
			
		}
		cout << ans + 1 << '\n';
	}
}