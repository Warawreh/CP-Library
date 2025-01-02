#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n;
	cin>>n;
	multiset<int> st;
	ll ans = 0,res=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ans += x;
		st.insert(x);
		while(st.size() && *st.begin() <= st.size()){
			ans -= *st.begin();
			st.erase(st.begin());
		}
		ll v = st.size();
		res = max(res , ans - (v * (v+1)/2));
	}	
	cout << res << '\n';
}