#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	cin>>n;
	vector<string> a(n);
	int ans = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		// a[i] = "999999999";
		if(i){
			if(a[i].size() < a[i-1].size()){
				int need = a[i-1].size() - a[i].size();
				string tmp = a[i] + string(need , '9');
				if(tmp <= a[i-1]){
					ans += need + 1;
					a[i] = a[i] + string(need + 1 , '0');
				}else{
					ans += need;
					int x = pow(10 , need);
					int lo = 0,hi = x-1;
					string at = "";
					while(lo <= hi){
						int md = (lo + hi)/2;
						string v = to_string(md);
						v = string(need - v.size() , '0') + v;
						string tmp = a[i] + v;
						if(tmp.size() == a[i-1].size() && tmp > a[i-1]){
							hi = md-1;
							at = v;
						}else lo = md+1;
					}
					assert(at != "");
					a[i] = a[i] + at;
				}
			}else if(a[i].size() == a[i-1].size() && a[i] <= a[i-1]){
				a[i] += '0';
				ans++;
			}
		}
		// cerr << i << ' ' << a[i] << '\n';
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}