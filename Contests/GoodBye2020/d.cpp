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
		vector<int> w(n);
		ll ans = 0;
		for(int i=0;i<n;i++){
			cin>>w[i];
			ans+=w[i];
		}
		vector<int> st;
		vector<int> in(n);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			u--;v--;
			in[u]++;
			in[v]++;
		}
		for(int i=0;i<n;i++){
			for(int x=0;x<in[i] - 1;x++)
				st.push_back(w[i]);
		}
		sort(all(st));
		cout << ans << ' ';
		for(int i=0;i<n-2;i++){
			ans += st.back();
			st.pop_back();
			cout << ans << ' ';
		}
		cout << '\n';
	}
}