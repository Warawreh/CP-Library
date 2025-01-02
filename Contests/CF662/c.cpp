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
		map<int,int>f;
		vector<int> a(n);
		set<int> st;
		int mx = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			f[a[i]]++;
			st.insert(a[i]);
			mx = max(mx , f[a[i]]);
		}
		vector<int> w(mx,0);
		if(mx == 1){
			cout << n << '\n';
			continue;
		}
		int at = 0;
		for(int x : st){
			for(int i=0;i<f[x];i++){
				if(f[x] != mx && at == mx-1){
					at = 0;
				}
				w[at]++;
				at++;
				at %= mx;
			}
		}
		sort(all(w));
		if(w.size() == 1)cout << w[0] << '\n';
		else cout << w[1]-1 << '\n';
	}
}