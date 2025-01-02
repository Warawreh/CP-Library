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
		multiset<int> st;
		for(int i=0;i<n;i++){
			cin>>a[i];
			st.insert(-a[i]);
		}
		int t = 0,hold = 0;
		while(st.size()){
			int cur = -*st.begin();
			st.erase(st.begin());
			if(hold > 0)st.insert(-hold);
			hold = cur-1;
			cur--;
			t = !t;
		}
		cout << (t ? "T" : "HL") << '\n';
	}	
}