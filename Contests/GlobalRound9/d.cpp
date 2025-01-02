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
		vector<int> a(n),f(n+1);
		set<int> st,nd;
		for(int i=0;i<=n;i++)st.insert(i);
		for(int i=0;i<n;i++){
			cin>>a[i];
			f[a[i]]++;
			if(a[i] != i)nd.insert(i);
			st.erase(a[i]);
		}
		vector<int> ans;
		while(nd.size()){
			int c = *st.begin();
			if(c == n){
				int to = *nd.begin();
				ans.push_back(to + 1);
				f[a[to]]--;
				if(!f[a[to]])st.insert(a[to]);
				f[n]++;
				a[to] = n;
				st.erase(n);
				continue;
			}
			ans.push_back(c + 1);
			f[a[c]]--;
			nd.erase(c);
			if(!f[a[c]])st.insert(a[c]);
			f[c]++;
			a[c] = c;
			st.erase(c);
		}
		cout << ans.size() << '\n';
		for(int i : ans)cout << i << ' ';
		cout << '\n';
	}
}