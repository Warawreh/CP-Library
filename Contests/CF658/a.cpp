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
		string a,b;
		cin>>n>>a>>b;
		int at = 0,f=0;
		vector<int> ans;
		for(int i=0;i<n;i++){
			int c = (a[at] - '0') ^ f;
			// cerr << at << ' ' << c << ' ' << b[n-i-1] << '\n';
			if(c == b[n-i-1] - '0'){
				ans.push_back(1);
			}
			if(f == 0){
				at = n - at - 1;
			}else{
				at = (i + 1)/2;
			}
			ans.push_back(n-i);
			f ^= 1;
		}
		cout << ans.size();
		for(int i : ans)cout << ' ' << i;
		cout << '\n';
	}
}